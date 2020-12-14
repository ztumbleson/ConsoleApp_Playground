#include "SleepLog.h"
#include <iostream>

//Constructors

SleepLog::SleepLog(int m, int d, int y, double hours) {
	month = m;
	day = d;
	year = y;
	hoursSlept = hours;
}

//Methods

bool SleepLog::DateIsValid() {
	//Todo date validation
	return true;
}

void SleepLog::PrintSleepLog() {
	std::cout << "Date: " + month << "/" << day << "/" << year
		<< " Hours Slept: " << hoursSlept << std::endl;
}

//Setters
