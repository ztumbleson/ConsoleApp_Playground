#pragma once

#include "AppTemplate.h"
#include "AppConstants.h"
#include <string>

class AppHub;

/// <summary>
/// The test app class is an example to show how to add new apps to 
/// the hub, and define their separate functionality
/// </summary>
class TestApp : AppTemplate 
{
public:

	TestApp() : AppTemplate(appConsts::TEST_APP_ID, appConsts::TEST_APP_DISPLAY_NAME){
		hasVisited = false;
	}

	TestApp(std::string appID, std::string displayName) : AppTemplate(appID, displayName) {
		hasVisited = false;
	}

	void RunApp();
	static void Startup(AppHub &hub);
private:
	bool hasVisited;
};

