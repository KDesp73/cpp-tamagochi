#pragma once

#include "food.h"
#include "status.h"

class Burger : public Food {
public:
	Burger() : Food(){
		this->type = "Burger";
		this->status = Status::Full;
	} 
};
