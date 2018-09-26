#include <stdio.h>
#include <iostream>
#include "Server.h"

int main(int argc, char **argv)
{

try
  {
    if (argc != 2)
    {
      std::cerr << "Usage: server <port>\n";
      return 1;
    }
	
	Server server;
	server.start_accept(atoi(argv[1]));
	std::cout<<"exiting"<<std::endl;
	
}
catch (std::exception& e)
  {
    std::cerr << "Exception: " << e.what() << "\n";
  }
	
	return 0;
}
