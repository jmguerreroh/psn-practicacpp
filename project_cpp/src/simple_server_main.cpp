// Server main

#include "../include/ServerSocket.hpp"
#include "../include/SocketException.hpp"
#include "../include/Utils.hpp"
#include <string>
#include <iostream>

int main ( int argc, char *argv[] )
{
	srand(time(NULL)); 
	std::cout << "Server running....\n";

	try
  	{
		// Create the socket
		ServerSocket server ( 30000 );

		while ( true )
		{
			Utils utils;
			ServerSocket new_sock;
			server.accept ( new_sock );
			std::cout << "Conection accepted" << std::endl;
			try
			{
				while ( true )
				{
					// Read message from client
					std::string data;
					new_sock >> data;
					std::cout << "We received this response from the client:\n\"" << data << "\"\n";

					// Tokenize the message
					const char delim = ',';
					std::vector<std::string> vdata;
					utils.tokenize(data, delim, vdata);
					std::cout << "TOKENIZE --> Data: " ;
					// *** NEW: for auto 
					for (auto &d: vdata) {
						std::cout << d << " - " ;
					}
					std::cout << std::endl;

					// Send message to client
					std::string msg = "server_param1,server_param2,server_param3";
					new_sock << msg;
				}
			}
			catch ( SocketException& ) {}
			std::cout << "Conection closed" << std::endl;
		}
	}
	catch ( SocketException& e )
	{
		std::cout << "Exception was caught:" << e.description() << "\nExiting.\n";
	}

	return 0;
}