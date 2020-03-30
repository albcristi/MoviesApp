#pragma once
#include <vector>
#include <string>

class errors : public std::exception
{
protected:
	std::vector<std::string> err;

public:
	//default constructor
	errors();
	//destructor
	virtual ~errors() {}

	errors(std::vector<std::string> _err) { this->err = _err; }

	virtual const char* what();
};

