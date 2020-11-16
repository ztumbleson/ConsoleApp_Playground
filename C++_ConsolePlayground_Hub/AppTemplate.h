#pragma once
#include <string>
#include "AppHub.h"
#include <iostream>

class AppHub;

/// <summary>
/// The App template class is a base class that other app classes must inherit from in order to 
/// run apps in the hub. 
/// 
/// The app template contains an app id, some kind of unique identifier as a string,
/// and an app display name, to be used in the hub main menu
/// 
/// The app hub also contains a virtual 'RunApp' method that must be implemented in the child class,
/// specifying what happens when the hub launches the app, and another method called Startup that allows the 
/// app to register itself with the hub when the application starts
/// </summary>
class AppTemplate
{
public:
	AppTemplate() {

	}

	AppTemplate(std::string appIDParam = "", std::string displayNameParam = "") {
		appID = appIDParam;
		displayName = displayNameParam;
	}

	~AppTemplate() {
		;
	}

	//Getters
	std::string GetAppID() { return appID; }
	std::string GetDisplayName() { return displayName; }

	//Virtual RunApp method, must be implemented by each app
	virtual void RunApp() { std::cout << "This app has not yet implemented it's version of RunApp()"; exit(1); }
	virtual void Startup(AppHub& hub) { std::cout << "An attempt was made to register an app that does not have a 'Startup' function defined."; exit(1); };
private:
	std::string appID;
	std::string displayName;
};

