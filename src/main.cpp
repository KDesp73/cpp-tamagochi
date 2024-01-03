#include "cli_kit.h"
#include "actions.h"
#include "include/menu.h"
#include "include/text.h"
#include "status.h"
#include "tamagochi.h"
#include "ui.h"
#include "utils.h"
#include "burger.h"
#include "cake.h"
#include <cstdlib>
#include <thread>
#include <chrono>

using namespace CliKit;

std::string pet_path = "./pixelart/dave/";

void timer(Tamagochi *tamagochi){
	while(true){
		tamagochi->progress();
		UI::render(tamagochi);

		using namespace std::this_thread; // sleep_for, sleep_until
		using namespace std::chrono; // nanoseconds, system_clock, seconds

		sleep_for(nanoseconds(10));
		sleep_until(system_clock::now() + seconds(1));

		if(tamagochi->status.count(Status::Dead)){
			UI::clearRender();
			UI::render(tamagochi);
			cout << endl << "Your Tamagochi died..." << endl; 
			cout << "Cause of death: " << Text::red << tamagochi->cause_of_death << Text::normal << endl << endl;
			cout << Text::blue << "Press Enter to continue..." << Text::normal;
			char input;
			do {
				input = cin.get();
			} while(input != '\n');
			Text::enableInputBuffering();
			return;	
		}

		UI::clearRender();
	}
}

void start(Tamagochi *tamagochi){
	std::thread progress_thread(timer, tamagochi);
	Text::disableInputBuffering();

	while (true) {

		if(tamagochi->status.count(Status::Dead)){
			progress_thread.join();
			return;
		}

		Action action = UI::handleKeys();

		switch (action) {
			case Action::Progress:
				tamagochi->progress(10);
				break;
			case Action::Exit:
				Text::enableInputBuffering();
				exit(0);
				break;
			case Action::Default:
				break;
			case Action::Feed:
				// CliKit::Text::enableInputBuffering();
				// cout << "[1] Burger, [2] Cake: ";
				// int food;
				// do{
				// 	cin >> food;
				// 	switch (food) {
				// 		case 1:
				// 			tamagochi->feed(Burger());
				// 			break;
				// 		case 2:
				// 			tamagochi->feed(Cake());
				// 			break;
				// 	} 
				// } while(food != 1 && food != 2);	
				// CliKit::Text::disableInputBuffering();

				tamagochi->feed(Burger());
				break;
			case Action::Sleep:
				tamagochi->sleep();
				break;
			case Action::Clean:
				tamagochi->clean();
				break;
			case Action::Discipline:
				break;
		}
		
		// UI::clearRender();	
	}
	progress_thread.join();
}

void selectSkin(Tamagochi *tamagochi){
	int skin = Menu::menu(Text::green + "Select pet" + Text::normal, 2, {"Dave", "ChatGPT", "Back"});


	// TODO: change to absolute path
	switch (skin) {
		case 0:
			pet_path = Utils::getProjectPath() + "/dave/";
			break;
		case 1:
			pet_path = Utils::getProjectPath() + "/chatgpt/";
			break;
		case 2:
			break;
	}
}

int main(int argc, char **argv){
	while (true) {
		Tamagochi *tamagochi = new Tamagochi(pet_path);

		int choice = Menu::menu(Text::red + "Tamagochi" + Text::normal, 1, {"Start", "Select Pet", "Exit"});
		switch (choice) {
			case 0:
				tamagochi->add_status(Status::Happy);
				// Start the game
				start(tamagochi);
				break;
			case 1: 
				selectSkin(tamagochi);
				break;
			case 2:
				return 0;
		}
	}

	return 0;
}
