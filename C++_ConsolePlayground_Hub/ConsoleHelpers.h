#pragma once

#include <string>

///This file contains helper methods that are useful when formatting or printing things to the console
namespace ConsoleHelpers {
	static std::string PrintAsteriskLine(int lineLength) {
		return std::string(lineLength, '*');
	}
}