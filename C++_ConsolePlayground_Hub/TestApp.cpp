#include "TestApp.h"
#include "iostream"
#include "ConsoleHelpers.h"
#include <string>

void TestApp::RunApp() {
	const int LINE_LENGTH = 50;
	std::cout << "\n\n" << ConsoleHelpers::PrintAsteriskLine(LINE_LENGTH)
		<< "\n* | Starting the Test App\n* | Please wait\n"
		<< ConsoleHelpers::PrintAsteriskLine(LINE_LENGTH) << std::endl;
	
	if (!hasVisited) {
		hasVisited = true;
		std::cout << "\n\nHi, welcome to the test app! I'm Ben, and I'm in charge around here.\n\n";

		std::cout << "What's your name?: ";
		std::string name;
		//eat the newline
		std::cin.get();
		std::getline(std::cin, name);

		std::cout << "\nHello, " << name << "!\n";

		std::cout << "It's nice to meet you, but I'm a little busy right now. Please come back later!\n\n";
	}
	else {
		std::cout << "\n\nHi I'm- ...you again? I told you. I'm busy. Now get out!\n\n";
		std::cin.get();
	}
	
	std::cout << "\n" << ConsoleHelpers::PrintAsteriskLine(LINE_LENGTH)
		<< "\n* | Closing the Test App\n* | Press enter to return to the Main Menu\n"
		<< ConsoleHelpers::PrintAsteriskLine(LINE_LENGTH) << std::endl;

	std::cin.ignore();
}

void TestApp::Startup(AppHub &hub) {
	TestApp* testAppPtr = new TestApp();
	hub.RegisterApp(testAppPtr);
}