#include "utils.h"
#include "status.h"
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

string Utils::get_current_time(){
	// current date/time based on current system
	time_t now = time(0);

	// convert now to string form
	char* dt = ctime(&now);

	// convert now to tm struct for UTC
	// tm *gmtm = gmtime(&now);
	// dt = asctime(gmtm);

	return dt;
}

string Utils::status_to_string(Status status){
	switch (status) { 
		case Status::Sleepy:
			return "Sleepy";
		case Status::Full:
			return "Full";
		case Status::Hungry:
			return "Hungry";
		case Status::Energized:
			return "Energized";
		case Status::Happy:
			return "Happy";
		case Status::Sad:
			return "Sad";
		case Status::Clean:
			return "Clean";
		case Status::Dirty:
			return "Dirty";
		default:
			std::cerr << "Unknown status" << endl;
			return "error";
	}
}
