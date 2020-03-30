#include "MovieValidator.h"
#include "errors.h"


MovieValidator::MovieValidator()
{
}

void MovieValidator::validator(Movie& toCheck)
{
	std::vector<std::string> ERRORS;

	if (toCheck.getName().size() <= 1) {
		ERRORS.push_back("Invalid movie name. The name contains at least two letters! \n");
	}

	if (toCheck.getGenre().size() <= 3) {
		ERRORS.push_back("Invalid Genre for the movie,genre has at least four letters! \n");
	}

	if (toCheck.getTrailer().find("http") != 0) {
		ERRORS.push_back("Invalid link for the trailer! \n");
	}

	if (toCheck.getYear() <= 1900) {
		ERRORS.push_back("Year of Release has to be greater than 1900 \n");
	}

	if (toCheck.getLikes() < 0) {
		ERRORS.push_back("The number of likes can not be less than 0 \n");
	}

	if (ERRORS.size() > 0) {
		throw errors(ERRORS);
	}

}


MovieValidator::~MovieValidator()
{
}
