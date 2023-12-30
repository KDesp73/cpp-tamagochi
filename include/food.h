#pragma once

#include "status.h"
#include <string>

class Food {
public:
	Status status;
	std::string type;

	~Food() = default;
	Food() = default;
};
