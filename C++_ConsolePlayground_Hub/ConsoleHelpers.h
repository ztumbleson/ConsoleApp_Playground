#pragma once

#include <string>

///This file contains helper methods that are useful when formatting or printing things to the console
namespace ConsoleHelpers {
	static std::string PrintAsteriskLine(int lineLength) {
		return std::string(lineLength, '*');
	}

	static std::string PrintStartingAppBlock(std::string appName) {
		return "\n\n" + PrintAsteriskLine(50) + "\n* | Starting the " + appName + " app.\n" + 
			"* | Please wait\n" + PrintAsteriskLine(50) + "\n\n";
	}

	static std::string PrintClosingAppBlock(std::string appName) {
		return "\n\n" + PrintAsteriskLine(50) + "\n* | Closing the " + appName + " app.\n" +
			"* | Press enter to return to the main menu\n" + PrintAsteriskLine(50) + "\n\n";
	}
}