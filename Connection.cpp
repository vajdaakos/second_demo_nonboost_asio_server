#include "Connection.h"
#include <iostream>

#include <boost/bind.hpp>
#include "Signer_and_verifier.h"
using asio::ip::tcp;
namespace ssl = asio::ssl;
typedef ssl::stream<tcp::socket> ssl_socket;
Connection::Connection(asio::io_service& io_service, asio::ssl::context& context,std::vector<std::string> &jobs_with_path)
    : service_(io_service),socket_(io_service, context),jobs_with_path(jobs_with_path)
{
	
	
	


}

Connection::~Connection()
{
}

ssl_socket::lowest_layer_type& Connection::socket()
{
	return socket_.lowest_layer();
}

void Connection::start()
{
	socket_.async_handshake(asio::ssl::stream_base::server,
        [me=shared_from_this()]( std::error_code const &ec){me->handle_handshake(ec);});

}

void Connection::handle_handshake( std::error_code const &ec)
{
	std::cout<<"Wellcome "<<socket().remote_endpoint().address().to_string()<<":"<<socket().remote_endpoint().port()<<std::endl;
	if (!ec)
          {
			  do_login_header_read();
			  //service_.run();
			  //message_io_service.run();
          }
          else
          {
			  std::cout<<ec<<std::endl;
			socket_.shutdown();
			socket_.lowest_layer().close();
			  return;
          }
}

void Connection::do_login_header_read()
{
	
    asio::async_read(socket_,asio::buffer(header),
        [self=shared_from_this()](std::error_code ec, std::size_t bytes_transferred)
        {
          if (!ec) 
          {
			

			unsigned long long int body_lenght=self->get_full_body_lenght(self->header);
			std::string sender=self->get_sender(self->header);
			unsigned int seq=self->get_seq(self->header);
			self->message_id=seq;
			unsigned int response_to=self->get_response_to(self->header);
			unsigned int type=self->get_type(self->header);
			std::string full_path=self->get_full_path(self->header);

			  if (body_lenght>0)
				self->do_login_body_read(body_lenght,sender);

          }
          else
          {
			  std::cout<<ec<<std::endl;
			  
			  return;

          }
        });
}
void Connection::do_login_body_read(unsigned long long int full_body_lenght,std::string sender)
{
	
	body=(unsigned char*)malloc(full_body_lenght);
    asio::async_read(socket_,asio::buffer(body,full_body_lenght),
        [this, self=shared_from_this(),sender](std::error_code ec, std::size_t bytes_transferred)
        {
          if (!ec) 
			{

				bool authentic=verify_client(sender,body);
				free(body);
				if(authentic){
				std::cout<<"Authenticated."<<std::endl;
				self->on_authenticated(sender);
				}
			}
		else
			{
			
			}
		});
		
}
void Connection::on_authenticated(std::string sender)
{
	message_id++;
	std::string response_string="Wellcome " + socket().remote_endpoint().address().to_string() + ":" + std::to_string(socket().remote_endpoint().port()) + " aka: " + sender + ":"+ std::to_string(socket().remote_endpoint().port());
	Auth_answer_message auth_message_response(message_id,response_string);
	send_message(auth_message_response);
	
}
void Connection::send_message(Message message)
{
	unsigned char binary_message[512+message.get_body_lenght()];
	set_body_lenght_message_field(message, binary_message);
	set_sender_message_field(message, binary_message);
	set_seq_message_field(message, binary_message);
	set_response_to_message_field(message, binary_message);
	set_type_message_field(message, binary_message);
	set_full_path_message_field(message, binary_message);
	set_body_message_field(message, binary_message);
	std::cout<<"Sending answer"<<std::endl;
	std::cout<<"seq: "<<message.get_seq()<<std::endl; 
	std::cout<<"response to= "<<message.get_response_to()<<std::endl; 
	if(message.get_type()==15 || message.get_type()==4|| message.get_type()==11) 
	{
	asio::async_write(socket_,
	asio::buffer(binary_message,512+message.get_body_lenght()),
	[=,me=shared_from_this()](std::error_code const &ec, std::size_t bytes_xfer)
	{
		std::cout<<"Sent:"<<bytes_xfer<<std::endl;
		me->do_header_read();
		//me->check_auth_message_answer(ec, bytes_xfer);
		//me->send_message_postprocess(ec, bytes_xfer);
	});
	}
}


void Connection::set_body_lenght_message_field(Message message,
unsigned char* buffer)
{
	unsigned int byte_position=0;
	unsigned long long int body_lenght=message.get_body_lenght();
	memcpy(buffer+byte_position,&body_lenght,sizeof (unsigned long long int));
}

void Connection::set_sender_message_field(Message message, 
unsigned char* buffer)
{
	unsigned int byte_position=sizeof (unsigned long long int);
	std::string sender=message.get_sender();
	
	char csender[64];
	strcpy(csender,sender.c_str());
	memcpy(buffer+byte_position,csender,64);
	
}
void Connection::set_seq_message_field(Message message,
unsigned char* buffer)
{
	unsigned int byte_position=sizeof (unsigned long long int)+64;
	unsigned int seq=message.get_seq();
	
	memcpy(buffer+byte_position,&seq,sizeof (unsigned int));
}

void Connection::set_response_to_message_field(Message message,
unsigned char* buffer)
{
	unsigned int byte_position=sizeof (unsigned long long int)+64+
	sizeof (unsigned int);
	unsigned int response_to=message.get_response_to();
	memcpy(buffer+byte_position,&response_to,sizeof (unsigned int));
}

void Connection::set_type_message_field(Message message,
unsigned char* buffer)
{
	unsigned int byte_position=sizeof (unsigned long long int)+64+
	sizeof (unsigned int)+sizeof (unsigned int);
	unsigned int type=message.get_type();
	memcpy(buffer+byte_position,&type,sizeof (unsigned int));
}

void Connection::set_full_path_message_field(Message message, 
unsigned char* buffer)
{
	unsigned int byte_position=sizeof (unsigned long long int)+64+
	sizeof (unsigned int)+sizeof (unsigned int)+sizeof (unsigned int);
	std::string full_path=message.get_full_path();
	char cfullpath[428];
	strcpy(cfullpath,full_path.c_str());
	memcpy(buffer+byte_position,cfullpath,428);
	
	
}
void Connection::set_body_message_field(Message message, 
unsigned char* buffer)
{
	
	unsigned char* body=message.get_body();
	std::cout<<message.get_body()<<std::endl;
	int n=message.get_body_lenght();
	memcpy(buffer+512,body,n);
	
}

void Connection::do_header_read_again()
{
	
	std::cout<<"body_read_again"<<std::endl;

	
	do_header_read();
}

void Connection::do_jobsend(int seq)
{
	if(!jobs_with_path.empty()){
		
	message_id++;
	Job_send_message job_send_message(message_id,seq,jobs_with_path);
	send_message(job_send_message);
	}
	else
	{
		std::cout<<"Nincs több job"<<std::endl;
		message_id++;
		close_connection close(message_id);
		send_message(close);
	}
}

void Connection::do_header_read()
{
	message_id++;
	
	std::cout<<"body_read"<<std::endl;
	
	
    asio::async_read(socket_,asio::buffer(this->header),
        [this,self=shared_from_this()](std::error_code ec, std::size_t bytes_transferred)
        {
			
          if (!ec) 
          {
			std::cout<<"Bytes transfered:" <<bytes_transferred<<std::endl;
			std::cout<<"header data: "<<std::endl;
			unsigned long long int body_lenght=self->get_full_body_lenght(self->header);
			std::cout<<"body_lenght: " <<body_lenght<<std::endl;
			std::string sender=self->get_sender(self->header);
			std::cout<<"sender: " <<sender<<std::endl;
			unsigned int seq=self->get_seq(self->header);
			std::cout<<"seq: " <<seq<<std::endl;
			unsigned int response_to=self->get_response_to(self->header);
			std::cout<<"response_to: " <<response_to<<std::endl;
			unsigned int type=self->get_type(self->header);
			std::cout<<"type: " <<type<<std::endl;
			std::string full_path=self->get_full_path(self->header);
			std::cout<<"full_path: " <<full_path<<std::endl;
			std::cout<<"--------------------------"<<std::endl;
				if (body_lenght>0)
				{
					
					self->do_body_read(body_lenght,sender);
				}
				else
				{
					std::cout<<"Message type:"<<type<<std::endl;
					if(self->get_type(self->header)==2)
					{
						
						self->do_jobsend(seq);
						//self->do_header_read_again();
						
						
					}
					else{
						
						std::cout<<self->get_type(self->header)<<std::endl;
					}
				}
				

          }
          else
          {
			  if(ec.value() != 1)
			  std::cout<<ec.value()<<std::endl;
			  

          }
        });
}



void Connection::do_body_read(unsigned long long int full_body_lenght,std::string sender)
{
	body=(unsigned char*)malloc(full_body_lenght);
    asio::async_read(socket_,asio::buffer(body,full_body_lenght),
        [this, self=shared_from_this(),sender](std::error_code ec, std::size_t bytes_transferred)
        {
          if (!ec) 
			{

				

			}
		else
			{
			
			}
		});
		
}
bool Connection::verify_client(std::string sender, unsigned char* signature)
{
	Signer_and_verifier signature_verifier;
	return signature_verifier.verifySignature(sender,reinterpret_cast<char *>(signature));
}

unsigned long long int Connection::get_full_body_lenght(unsigned char* byte_array)
  {
	int byte_position=0;
	unsigned long long int full_body_lenght;
	memcpy(&full_body_lenght,byte_array+byte_position,sizeof (unsigned long long int));
    return full_body_lenght;
  }
  std::string Connection::get_sender(unsigned char* byte_array)
  {
	  int byte_position=sizeof(unsigned long long int);
	  char csender [64];
	  memcpy(csender,byte_array+byte_position,64);
	  std::string sender(csender);
	  return sender;
  }
  unsigned int Connection::get_seq(unsigned char* byte_array)
  {
	unsigned int seq;
	int byte_position=sizeof(unsigned long long int)+64;
	memcpy(&seq,byte_array+byte_position,sizeof (unsigned int));
    return seq;
  }
  unsigned int Connection::get_response_to(unsigned char* byte_array)
  {
	unsigned int response_to;
	int byte_position=sizeof(unsigned long long int)+64+sizeof (unsigned int);
	memcpy(&response_to,byte_array+byte_position,sizeof (unsigned int));
    return response_to;
  }
  unsigned int Connection::get_type(unsigned char* byte_array)
  {
	unsigned int type;
	int byte_position=sizeof(unsigned long long int)+64+sizeof (unsigned int)+sizeof (unsigned int);
	memcpy(&type,byte_array+byte_position,sizeof (unsigned int));
    return type;
  }
std::string Connection::get_full_path(unsigned char* byte_array)
  {
	  int byte_position=sizeof(unsigned long long int)+64+sizeof (unsigned int)+sizeof (unsigned int)+sizeof(unsigned int);
	  char cfullpath [428];
	  memcpy(cfullpath,byte_array+byte_position,428);
	  std::string full_path(cfullpath);
	  return full_path;
  }
void Connection::print_message_by_fields(int bytes_transferred, unsigned long long int full_body_lenght, std::string sender, unsigned int seq,unsigned int response_to,unsigned int type, std::string full_path,unsigned char* body)
{
	  std::cout<<"bytes transferred        : "<<bytes_transferred<<std::endl;
	  std::cout<<"body_lenght              : "<<full_body_lenght<<std::endl;
	  std::cout<<"sender                   : "<<sender<<std::endl;
	  std::cout<<"seq                      : "<<seq<<std::endl;
	  std::cout<<"response to              : "<<response_to<<std::endl;
	  std::cout<<"type                     : "<<type<<std::endl;
	  std::cout<<"full path                : "<<full_path<<std::endl;
	  std::string string_body((char*)body);
	  std::cout<<"body                     : "<<body<<std::endl; 
	  
}
void Connection::print_header_message_by_fields(int bytes_transferred, unsigned long long int full_body_lenght, std::string sender, unsigned int seq,unsigned int response_to,unsigned int type, std::string full_path)
{
	  std::cout<<"bytes transferred        : "<<bytes_transferred<<std::endl;
	  std::cout<<"body_lenght              : "<<full_body_lenght<<std::endl;
	  std::cout<<"sender                   : "<<sender<<std::endl;
	  std::cout<<"seq                      : "<<seq<<std::endl;
	  std::cout<<"response to              : "<<response_to<<std::endl;
	  std::cout<<"type                     : "<<type<<std::endl;
	  std::cout<<"full path                : "<<full_path<<std::endl;
	  
	  
}
void get_body(unsigned char* byte_array,unsigned long long int full_body_lenght,unsigned char* body)
{
	  int byte_position=sizeof(unsigned long long int)+64+sizeof (unsigned int)+sizeof (unsigned int)+sizeof(unsigned int)+428;
	  std::cout<<"header lenght: "<<byte_position<<std::endl;
	  memcpy(body,byte_array+byte_position,full_body_lenght);
	  
}
