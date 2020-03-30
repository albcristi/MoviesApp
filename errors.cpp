#include "errors.h"
#include <iostream>


errors::errors()
{
}



const char* errors::what()
{
	std::string message("");
	for (auto er : this->err) {
		message.append(er);
	}

	{
		std::cout << message.c_str();


		return "";
	}
}
