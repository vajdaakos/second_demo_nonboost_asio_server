#ifndef CONNECTION_H
#define CONNECTION_H
#include "asio.hpp"
#include "asio/ssl.hpp"
#include <vector>
#include "Message.h"
#include "Auth_answer_message.h"
#include "Job_send_message.h"
#include "close_connection.h"
#include <string>
using asio::ip::tcp;
typedef asio::ssl::stream<asio::ip::tcp::socket> ssl_socket;
class Connection : public std::enable_shared_from_this<Connection>
{
public:
	Connection(asio::io_service&, asio::ssl::context&,std::vector<std::string>&);
	~Connection();
	ssl_socket::lowest_layer_type& socket();
	void start();
	
private:
	asio::io_service& service_;
	ssl_socket socket_;
	std::vector<std::string>& jobs_with_path;
	unsigned int message_id;
	bool verify_client(std::string,unsigned char*);
	unsigned char header[512];
	void do_jobsend(int);
	unsigned char *body;
	void handle_handshake(std::error_code const &);
	void do_header_read();
	
	void do_header_read_again();
	void do_body_read(unsigned long long int,std::string);
	void do_login_header_read();
	void do_login_body_read(unsigned long long int,std::string);
	unsigned long long int get_full_body_lenght(unsigned char*);
	unsigned int get_seq(unsigned char*);
	std::string get_sender(unsigned char*);
	unsigned int get_response_to(unsigned char*);
	unsigned int get_type(unsigned char*);
	std::string get_full_path(unsigned char*);
	void print_message_by_fields(int , unsigned long long int , std::string , unsigned int ,unsigned int ,unsigned int , std::string ,unsigned char* );
	void print_header_message_by_fields(int, unsigned long long int, std::string, unsigned int,unsigned int,unsigned int, std::string);
	void on_authenticated(std::string);
	void send_message(Message);
	
	void set_body_lenght_message_field(Message, unsigned char*);
	void set_sender_message_field(Message,unsigned char* );
	void set_seq_message_field(Message, unsigned char* );
	void set_response_to_message_field(Message, unsigned char* );
	void set_type_message_field(Message, unsigned char* );
	void set_full_path_message_field(Message, unsigned char* );
	void set_body_message_field(Message, unsigned char* );

};

#endif // CONNECTION_H
