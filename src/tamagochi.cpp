#include "tamagochi.h"
#include "food.h"
#include "include/files.h"
#include "status.h"
#include "utils.h"
#include <iostream>
#include <string>
#include <type_traits>

void Tamagochi::feed(Food food){
	this->add_status(food.status);
	this->last_fed = this->time;

	if(this->times_fed == 10) {
		this->status.clear();
		this->add_status(Status::Dead);
		this->cause_of_death = "Ate too many burgers";
	}

	if(time - last_fed < 10) this->times_fed++;
}

void Tamagochi::add_status(Status status){
	switch (status) {
		case Status::Clean:
			this->status.erase(Status::Dirty);
			break;
		case Status::Dirty:
			this->status.erase(Status::Clean);
			break;
		case Status::Happy:
			this->status.erase(Status::Sad);
			break;
		case Status::Sad:
			this->status.erase(Status::Happy);
			break;
		case Status::Full:
			this->status.erase(Status::Hungry);
			break;
		case Status::Hungry:
			this->status.erase(Status::Full);
			break;
		case Status::Energized:
			this->status.erase(Status::Sleepy);
			break;
		case Status::Sleepy:
			this->status.erase(Status::Energized);
			break;
	}

	this->status.insert(status);
}

void Tamagochi::clean(){
	this->add_status(Status::Clean);
	this->last_cleaned = this->time;

	if(this->times_cleaned == 10) {
		this->status.clear();
		this->add_status(Status::Dead);
		this->cause_of_death = "Too clean";
	}

	if(time - last_cleaned < 10) this->times_cleaned++;
}

void Tamagochi::print(){
	// TODO: change to absolute path
	std::string happy = CliKit::Files::readFile("./pixelart/happy");
	std::string sad = CliKit::Files::readFile("./pixelart/sad");
	std::string sleepy = CliKit::Files::readFile("./pixelart/sleepy");
	std::string hungry = CliKit::Files::readFile("./pixelart/hungry");
	std::string dead = CliKit::Files::readFile("./pixelart/dead");

	if(this->status.count(Status::Sad)){
		std::cout << sad << std::endl;
	} else if(this->status.count(Status::Sleepy)) {
		std::cout << sleepy << std::endl;
	} else if(this->status.count(Status::Dead)){
		std::cout << dead << std::endl;
	} else {
		std::cout << happy << std::endl;
	}
}

string Tamagochi::to_string(){
	string str = "";
	str += "-Tamagochi-\n";
	str += "Status:\n";
	
	for(Status status : this->status){
		str += "\t" + Utils::status_to_string(status) + "\n";
	}

	return str;
}

void Tamagochi::progress(){
	this->time++;
	this->checkTime();
}

void Tamagochi::progress(int num){
	this->time += num;
	this->checkTime();
}

void Tamagochi::sleep(){
	this->add_status(Status::Energized);
	this->last_slept = this->time;

	if(this->times_slept == 10) {
		this->status.clear();
		this->add_status(Status::Dead);
		this->cause_of_death = "Slept too much";
	}

	if(time - last_slept < 10) this->times_slept++;
}

std::string Tamagochi::status_to_string(){
	std::string str = "";

	int i = 0;
	for(Status status : this->status){
		if(i == this->status.size() - 1){
			str += Utils::status_to_string(status);
		} else {
			str += Utils::status_to_string(status) + ", ";
		}
		i++;
	}
	
	return str;
}

void Tamagochi::checkTime(){
	int sleepInterval = 30;
	int feedInterval = 15;
	int cleanInterval = 45;

	bool isSleepy = false;
	bool isHungry = false;
	bool isDirty = false;

	if(this->time - this->last_slept >= sleepInterval){
		this->add_status(Status::Sleepy);
		isSleepy = true;
	} 

	if(this->time - this->last_fed >= feedInterval){
		this->add_status(Status::Hungry);
		isHungry = true;
	}

	if(this->time - this->last_cleaned >= cleanInterval){
		this->add_status(Status::Dirty);
		isDirty = true;
	}

	bool isSad = (isDirty && isHungry) || (isDirty && isSleepy) || (isHungry && isSleepy);
	if(isSad){
		this->add_status(Status::Sad);
		this->rounds_of_sadness++;
	} else {
		this->add_status(Status::Happy);
		this->rounds_of_sadness = 0;
	}

	if(this->rounds_of_sadness >= 100){
		this->status.clear();
		this->add_status(Status::Dead);
		this->cause_of_death = "Tamagochi was neglected for too long. I'm calling the CPS";
	}

}
