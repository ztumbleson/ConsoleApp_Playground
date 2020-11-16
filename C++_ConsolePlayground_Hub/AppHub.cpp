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
	DisplayMainMenu();
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
	char userInput;
	do {
		std::cin >> userInput;

		switch (userInput) {
			case '1':
				//TODO Figure out a better way to do this, use an enum somehow
				apps[0]->RunApp();
				break;
			case 'q':
				std::cout << "Bye Bye for now" << std::endl;
				break;
			default:
				break;
		}

		DisplayMainMenu();

	} while (userInput != 'q');

	
}
