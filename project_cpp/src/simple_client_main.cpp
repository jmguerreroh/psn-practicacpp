// Client main

#include "../include/ClientSocket.hpp"
#include "../include/SocketException.hpp"
#include "../include/Utils.hpp"
#include <iostream>
#include <string.h>
#include <vector>
#include <list>

int main ( int argc, char *argv[] )
{
	srand(time(NULL)); 
	Utils utils;

	try
	{
		ClientSocket client_socket ( "localhost", 30000 );

		std::string reply;
		try
		{
			// Send message to server
			client_socket << "client_param1,client_param2,client_param3";

			// Read message from server
			client_socket >> reply;
			std::cout << "We received this response from the server:\n\"" << reply << "\"\n";

			// Tokenize the message
			const char delim = ',';
			std::vector<std::string> vdata;
			utils.tokenize(reply, delim, vdata);
			std::cout << "TOKENIZE --> Data: " ;
			// *** NEW: for auto 
			for (auto &d: vdata) {
				std::cout << d << " - " ;
			}
			std::cout << std::endl;
		}
		catch ( SocketException& ) {}    
	}
	catch ( SocketException& e )
	{
		std::cout << "Exception was caught:" << e.description() << "\n";
	}
	return 0;
}