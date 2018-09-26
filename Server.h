#ifndef SERVER_H
#define SERVER_H
#include "asio.hpp"
#include "asio/ssl.hpp"
#include <vector>
#include <memory>
#include <string>
#include "Connection.h"
#include <dirent.h>
class Server
{
public:
	Server();
	~Server();
	
	void handle_accept();
	void start_accept(unsigned short);
	void handle_new_connection(std::shared_ptr<Connection>, std::error_code const &);
	

private:
	
	std::vector<std::string> read_jobfilenames_to_vector(std::string path);
	std::vector<std::string> jobs_with_path;
	asio::io_service io_service_;
	asio::ip::tcp::acceptor acceptor_;
	asio::ssl::context context_;
	
	
};

#endif // SERVER_H
