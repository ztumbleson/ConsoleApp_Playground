#include "TestApp.h"
#include "iostream"
#include "ConsoleHelpers.h"
#include <string>

void TestApp::RunApp() {
	
	if (!hasVisited) {
		hasVisited = true;
		std::cout << "\n\nHi, welcome to the test app! I'm Ben, and I'm in charge around here.\n\n";

		std::cout << "What's your name?: ";
		std::string name;
		//eat the newline
		std::cin.ignore();
		std::getline(std::cin, name);

		std::cout << "\nHello, " << name << "!\n";

		std::cout << "It's nice to meet you, but I'm a little busy right now. Please come back later!\n\n";
		
	}
	else {
		std::cout << "\n\nHi I'm- ...you again? I told you. I'm busy. Now get out!\n\n";
	}
}

void TestApp::Startup(AppHub &hub) {
	TestApp* testAppPtr = new TestApp();
	hub.RegisterApp(testAppPtr);
}