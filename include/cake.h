#pragma once

#include "food.h"
#include "status.h"

class Cake: Food {
public:
	Cake() : Food(){
		this->type = "Cake";
		this->status = Status::Happy;
	} 
};
