#pragma once

#include "status.h"
#include <string>

using namespace std;

namespace Utils {
	string get_current_time();
	string status_to_string(Status status);
};
