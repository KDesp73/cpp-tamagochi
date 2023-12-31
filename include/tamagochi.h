#pragma once

#include "food.h"
#include "status.h"
#include <string>
#include <unordered_set>


class Tamagochi {
public:
	int hunger = 0;
	int happiness = 5;

	std::unordered_set<Status> status;

	~Tamagochi() = default;
	Tamagochi() = default;

	void print();
	void feed(Food food);
	void clean();
	void sleep();
	void discipline();
	void add_status(Status status);
	std::string to_string();
	void progress();

private: 
	int health = 100;
	int time = 0;

	std::string last_fed;
	std::string last_cleaned;
	std::string last_slept;
};
