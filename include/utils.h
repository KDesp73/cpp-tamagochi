#pragma once

#include "actions.h"
#include "status.h"
#include <string>

using namespace std;

namespace Utils {
	string get_current_time();
	string status_to_string(Status status);
	string action_to_string(Action action);
};
