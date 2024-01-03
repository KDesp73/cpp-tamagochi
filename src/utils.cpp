#include "utils.h"
#include "actions.h"
#include "status.h"
#include <iostream>
#include <linux/limits.h>
#include <string>
#include <ctime>

#include <cstdio>
#include <cstring>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
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

string removeSubstring(string originalString, string substringToRemove) {
    size_t startPos = originalString.find(substringToRemove);
    while (startPos != std::string::npos) {
        originalString.erase(startPos, substringToRemove.length());
        startPos = originalString.find(substringToRemove, startPos);
    }

	return originalString;
}

std::string Utils::getExecutablePath() {
#if defined(_WIN32)
    char buffer[MAX_PATH];
    GetModuleFileName(nullptr, buffer, MAX_PATH);
    return std::string(buffer);
#elif defined(__linux__) || defined(__APPLE__)
    char buffer[PATH_MAX];
    ssize_t len = readlink("/proc/self/exe", buffer, sizeof(buffer) - 1);
    if (len != -1) {
        buffer[len] = '\0';
        return std::string(buffer);
    }
#endif
    return "";
}

string Utils::getProjectPath(){
	std::string executablePath = getExecutablePath();
	size_t lastSeparatorPos = executablePath.find_last_of("\\/");
	if (lastSeparatorPos != std::string::npos) {
		return removeSubstring(executablePath.substr(0, lastSeparatorPos), "build");
	}

	return "";
}
