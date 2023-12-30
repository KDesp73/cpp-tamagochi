#pragma once

#include "food.h"
#include "status.h"

class Burger : Food {
public:
	Burger() : Food(){
		this->type = "Burger";
		this->status = Status::Full;
	} 
};
