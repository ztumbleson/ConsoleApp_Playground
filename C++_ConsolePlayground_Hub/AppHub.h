#pragma once

#include "AppTemplate.h"
#include <vector>

class AppTemplate;

/// <summary>
/// AppHub contains the methods and members pertaining to the "main" hub app that 
/// allows user to switch between the apps that have been added to the application
/// </summary>
class AppHub
{
public:
	AppHub() {
		numApps = 0;
		apps = std::vector<AppTemplate*>();
	}

	~AppHub() {
		for (int i = 0; i < (int)apps.size(); i++) {
			delete apps[i];
		}
	}

	/// <summary>
	/// Primary method that handles running the app hub, and creates the infinite loop that only exists 
	/// based on user input
	/// </summary>
	bool RunHub();

	/// <summary>
	/// Method used by other projects/apps to register their apps in the hub so that they can be displayed
	/// and run from the hub main menu
	/// </summary>
	/// <returns></returns>
	bool RegisterApp(AppTemplate* app);

	/// <summary>
	/// Displays the main menu on the console
	/// </summary>
	void DisplayMainMenu();

	/// <summary>
	/// Method to hold the main waiting user input loop for the program
	/// </summary>
	void MainLoop();

private:
	//The number of apps currently registered and being displayed on the hub main menu
	int numApps;
	std::vector<AppTemplate*> apps;
};

