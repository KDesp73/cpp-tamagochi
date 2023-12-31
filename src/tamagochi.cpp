#include "tamagochi.h"
#include "food.h"
#include "include/files.h"
#include "status.h"
#include "utils.h"
#include <iostream>

void Tamagochi::feed(Food food){
	this->add_status(food.status);
	std::cout << "Tamagochi ate " << food.type << std::endl;
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
}

void Tamagochi::print(){
	// TODO: change to absolute path
	std::string happy = CliKit::Files::readFile("./pixelart/happy");
	std::string sad = CliKit::Files::readFile("./pixelart/sad");
	std::string sleepy = CliKit::Files::readFile("./pixelart/sleepy");
	std::string hungry = CliKit::Files::readFile("./pixelart/hungry");

	if(this->status.count(Status::Sad)){
		std::cout << sad << std::endl;
	} else if(this->status.count(Status::Sleepy)) {
		std::cout << sleepy << std::endl;
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
}

