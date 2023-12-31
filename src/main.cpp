#include "cli_kit.h"
#include "actions.h"
#include "tamagochi.h"
#include "ui.h"
#include "utils.h"
#include "burger.h"
#include "cake.h"
#include <cstdlib>
#include <thread>

using namespace CliKit;

Action action = Action::Default;

Action UI::handleKeys() {
    #ifdef _WIN32
        switch (_getch()) {
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
            default: cout << "Invalid Action\n";
        }
    #else
        switch (getchar()){
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
			case '\n':
				action = Action::Progress;
				break;
            default: cout << "Invalid Action\n";
        }
    #endif
	
	return Action::Default;
}

void start(Tamagochi *tamagochi){
	Text::disableInputBuffering();

	while (true) {

		UI::render(tamagochi);

		cout << Utils::action_to_string(action) << endl;

		switch (action) {
			case Action::Progress:
				tamagochi->progress();
				break;
			case Action::Exit:
				Text::enableInputBuffering();
				system("exit");
				break;
			case Action::Default:
				break;
			case Action::Feed:
				cout << "[1] Burger, [2] Cake: ";
				int food;
				do{
					cin >> food;
					switch (food) {
						case 1:
							tamagochi->feed(Burger());
							break;
						case 2:
							tamagochi->feed(Cake());
							break;
					} 
				} while(food != 1 && food != 2);	
				tamagochi->progress();
				break;
			case Action::Sleep:
				tamagochi->sleep();
				tamagochi->progress();
				break;
			case Action::Clean:
				tamagochi->clean();
				tamagochi->progress();
				break;
			case Action::Discipline:
				break;
		}
	}

}

int main(int argc, char **argv){
	std::thread get_action_thread(UI::handleKeys);

	Tamagochi *tamagochi = new Tamagochi();

	int choice = Menu::menu(Text::red + "Tamagochi" + Text::normal, 1, {"Start", "Exit"});

	switch (choice) {
		case 0:
			// Start the game
			start(tamagochi);
			break;
		case 1:
			return 0;
	}
	
	get_action_thread.join();
	return 0;
}
