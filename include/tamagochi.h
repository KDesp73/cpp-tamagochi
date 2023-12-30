#pragma once

#include "food.h"
#include "status.h"
#include <string>
#include <unordered_set>


class Tamagochi {
public:
	int hunger = 0;
	int happiness = 5;
	int discipline;

	std::unordered_set<Status> status;

	~Tamagochi() = default;
	Tamagochi() = default;

	void print();
	void feed(Food food);
	void clean();
	void add_status(Status status);
	std::string to_string();

private: 
	int health = 100;

	std::string last_fed;
	std::string last_cleaned;
	std::string last_slept;
};
