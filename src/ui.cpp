
#include "ui.h"
#include "actions.h"
#include "include/text.h"
#include "tamagochi.h"
#include <cstdio>
#include <iostream>

using namespace std;

void UI::render(Tamagochi *tamagochi){
	cout << endl;

	tamagochi->print();

	cout << endl << endl << "Actions: [z] Clean, [x] Feed, [c] Sleep, [v] Discipline, [Enter] Progress, [q] Exit" << endl;
	// CliKit::Text::clearScreen();
}
