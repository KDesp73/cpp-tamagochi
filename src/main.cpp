#include <cstdlib>
#include <iostream>
#include "cli_kit.h"
#include "include/text.h"
#include "status.h"
#include "tamagochi.h"
#include "utils.h"

using namespace CliKit;

int main(int argc, char **argv){
	Tamagochi *tamagochi = new Tamagochi();

	int choice = Menu::menu(Text::red + "Tamagochi" + Text::normal, 1, {"Start", "Exit"});

	switch (choice) {
		case 0:
			// Start the game

			break;
		case 1:
			return 0;
	}

	return 0;
}
