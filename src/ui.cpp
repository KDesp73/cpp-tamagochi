
#include "ui.h"
#include "actions.h"
#include "include/files.h"
#include "include/text.h"
#include "tamagochi.h"
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

void UI::clearRender(){
	CliKit::Text::clearScreen();
}

void UI::render(Tamagochi *tamagochi){
	// cout << "Time: " << tamagochi->getTime() << endl;	
	cout << "Status: " << tamagochi->status_to_string() <<  endl << endl;

	tamagochi->print();

	cout << endl << endl << "Actions: [z] Clean, [x] Feed, [c] Sleep, [Space] Progress, [q] Exit" << endl;
}


Action UI::handleKeys() {
	Action action;
    #ifdef _WIN32
        switch (_getch()) {
    #else
        switch (getchar()){
    #endif
			case 'z': 
			case 'Z': 
				action = Action::Clean;
				break;
			case 'x': 
			case 'X': 
				action = Action::Feed;
				break;
			case 'c': 
			case 'C': 
				action = Action::Sleep;
				break;
			case 'v': 
			case 'V': 
				action = Action::Discipline;
				break;
			case 'q': 
			case 'Q': 
				action = Action::Exit;
				break;
			case ' ':
				action = Action::Progress;
				break;
            default: cout << "Invalid Action\n";
        }
	return action;
}

