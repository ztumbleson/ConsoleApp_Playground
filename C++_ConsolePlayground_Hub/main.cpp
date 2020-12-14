/*
*  main.cpp
*
*  Main file for running framework applications that allows the user
*  to select which console app they'd like to launch. Handles application
*  switching, as well as user info and quitting
*
*  This description is current as of 11/15/2020, but will be updated
*  periodically as more functionality is added
*
*
 */

#include <iostream>
#include "AppHub.h"
#include "TestApp.h"
#include "SleepTracker.h"
using namespace std;

void AppStartups(AppHub &hub);

int main()
{
    AppHub hub = AppHub();
   
    AppStartups(hub);
      
    bool exitSuccess = hub.RunHub();
    std::cout << std::endl << std::endl << "Exiting...";
    return EXIT_SUCCESS;
}

/// <summary>
/// Method to register apps and do any related startup tasks on a per-app basis
/// </summary>
/// <param name="hub">Reference parameter to the current hub object that will be run later</param>
void AppStartups(AppHub &hub) {
    
    std::cout << "Registering Apps: \n\n";
    TestApp::Startup(hub);
    SleepTracker::Startup(hub);
}


