#pragma once

#include "food.h"
#include "status.h"
#include <string>
#include <unordered_set>


class Tamagochi {
public:
	int hunger = 0;
	int happiness = 5;
	std::string cause_of_death = "";

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
	void progress(int num);
	std::string status_to_string();
	int getTime() {return time;}
	void checkTime();
private: 
	int health = 100;
	int time = 0;

	int times_fed = 0;
	int times_cleaned = 0;
	int times_slept = 0;
	int last_fed = 0;
	int last_cleaned = 0;
	int last_slept = 0;
	int rounds_of_sadness = 0;
};
