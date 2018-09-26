#include "Server.h"
#include <iostream>

#include <boost/bind.hpp>
//shared_handler_t=std::shared_ptr<Connection>
using asio::ip::tcp;
namespace ssl = asio::ssl;
typedef ssl::stream<tcp::socket> ssl_socket;
Server::Server()
    : acceptor_(io_service_), context_(asio::ssl::context::tlsv1)
  {

    
  }
  std::vector<std::string> Server::read_jobfilenames_to_vector(std::string path = "../jobfiles") {

    DIR*    dir;
    dirent* pdir;
    std::vector<std::string> files;

    dir = opendir(path.c_str());

    while (pdir = readdir(dir)) {
        files.push_back(pdir->d_name);
    }
    
    return files;
}
void Server::start_accept(unsigned short port)
{
	std::vector<std::string> jobfilenames=read_jobfilenames_to_vector();


	for(auto name:jobfilenames)
	{
		
		if(name != "." && name !="..")
		{
			jobs_with_path.push_back("../jobfiles/"+name);
		}
		
	}
	
	asio::ip::tcp::endpoint endpoint(asio::ip::tcp::v4(), port);
acceptor_.open(endpoint.protocol());
acceptor_.set_option(tcp::acceptor::reuse_address(true));
acceptor_.bind(endpoint);
acceptor_.listen();
    context_.set_options(
        asio::ssl::context::default_workarounds
        | asio::ssl::context::no_sslv2
        | asio::ssl::context::single_dh_use);
    
    context_.use_certificate_chain_file("../certs/server.crt");
    context_.use_private_key_file("../certs/server.key", asio::ssl::context::pem);
    context_.use_tmp_dh_file("../certs/dh2048.pem");
	auto connection=std::make_shared<Connection>(io_service_,context_, jobs_with_path);
    
		  
	acceptor_.async_accept(connection->socket()
	,[this,connection](auto error)
	{
		this->handle_new_connection(connection, error);
	});
	io_service_.run();
	/*
	for(int i=0; i<5; ++i)
{
thread_pool_.emplace_back( [=]{io_service_.run();} );
}
for (auto& th : thread_pool_) 
    th.join();*/
}


Server::~Server()
{
}


	

void Server::handle_new_connection(std::shared_ptr<Connection> connection, std::error_code const & error)
{

	if(error)
	{
		std::cout<<"Connection accepting failed"<<std::endl;
		std::cout<<error<<std::endl;
		return;
	}
	connection->start();
	
	auto new_connection=std::make_shared<Connection>(io_service_,context_,jobs_with_path);
	acceptor_.async_accept(new_connection->socket()
	,[this,new_connection](auto error)
	{
		this->handle_new_connection(new_connection, error);
	});
	
}

