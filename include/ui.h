#pragma once

#include "actions.h"
#include "tamagochi.h"

namespace UI {
	Action handleKeys();
	void render(Tamagochi *tamagochi);
	void clearRender();
};
