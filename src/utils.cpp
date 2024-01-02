#include "utils.h"
#include "actions.h"
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
		case Status::Dead:
			return "Dead";
		default:
			std::cerr << "Unknown status" << endl;
			return "error";
	}
}

string Utils::action_to_string(Action action){
	switch (action) {
        case Action::Feed:
			return "Feed";
        case Action::Sleep:
			return "Sleep";
        case Action::Clean:
			return "Clean";
        case Action::Discipline:
			return "Discipline";
		case Action::Exit:
			return "Exit";
		case Action::Progress:
			return "Progress";
		case Action::Default:
			return "Default";
		default:
			std::cerr << "Unknown action" << endl;
			return "error";
	}
}
