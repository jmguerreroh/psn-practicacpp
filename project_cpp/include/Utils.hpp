/**
 * @file Utils.hpp
 * @author José Miguel Guerrero Hernández (josemiguel.guerrero@urjc.es)
 * @brief generic and useful functions
 * @version 0.1
 * @date 2022-12-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef Utils_class
#define Utils_class

#include "Point.hpp"
#include <string.h>
#include <iostream>
#include <vector>

class Utils 
{
	public:
		/**
		 * @brief divide a string in tokens using a character
		 * 
		 * @param str string to divide
		 * @param delim char used as delimitator
		 * @param out vector containing the strings
		 */
		void tokenize(std::string const &str, const char delim, std::vector<std::string> &out);
};

#endif