/*
* AppHub.cpp
* 
* Author: Zachary Tumbleson
* Date Created: 11-15-2020
* 
* Brief: Contains method definitions for methods declared in AppHub.h
*/

#include <iostream>
#include <iomanip>
#include "AppHub.h"
#include "AppConstants.h"
#include "ConsoleHelpers.h"

bool AppHub::RunHub() {
	std::cout << "\nWelcome to the App Hub\n";
	bool errorsEncountered = false;
	
	//Run the hub
	MainLoop();

	return errorsEncountered;
}

bool AppHub::RegisterApp(AppTemplate* app) {
	this->apps.push_back(app);
	std::cout << "App with app ID: " << app->GetAppID() << " and display name: " << app->GetDisplayName()
		<< " was registered successfully\n\n";
	return true;
}

void AppHub::DisplayMainMenu() {
	std::cout << std::endl << "Main Menu" << std::endl;
	std::cout << ConsoleHelpers::PrintAsteriskLine(appConsts::APP_HUB_MAIN_MENU_ASTERISK_LENGTH) << std::endl;

	//Initialize app specifics
	int appCount = apps.size();
	int menuCount = 1;
	std::vector<AppTemplate*>::iterator appIter = apps.begin();

	for (appIter; appIter != apps.end(); appIter++, menuCount++) {
		AppTemplate* appPtr = *appIter;
		std::cout << menuCount << ".)" << appPtr->GetDisplayName() << std::endl;
	}

	std::cout << "q.)Quit" << std::endl;

	std::cout << ConsoleHelpers::PrintAsteriskLine(appConsts::APP_HUB_MAIN_MENU_ASTERISK_LENGTH) << std::endl;

	std::cout << std::endl << "Select an item by entering the corresponding number or letter, then pressing 'enter'."
		<< std::endl << "Please enter here: ";
}

void AppHub::MainLoop() {
	std::string userInput;
	char junk;
	do {
		DisplayMainMenu();
		std::cin >> userInput;

		if (userInput != "q") {
			//User not quitting, open app user has selected, subtract 1 to account for indexing from 0
			int appNum = std::stoi(userInput) - 1;
			if (appNum < apps.size()) {
				std::cout << ConsoleHelpers::PrintStartingAppBlock(apps[appNum]->GetDisplayName());
				apps[appNum]->RunApp();
				std::cout << ConsoleHelpers::PrintClosingAppBlock(apps[appNum]->GetDisplayName());
				std::cin.get();
			}
			else {
				std::cout << "Please enter a number or letter corresponding to an option in the list\n";
			}
		}

	} while (userInput != "q");
}
