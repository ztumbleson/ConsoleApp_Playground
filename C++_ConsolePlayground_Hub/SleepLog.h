#pragma once

/// <summary>
/// This class represents a sleep log for a single night of sleep
/// The month/day/year properties represent the date of the wake up day, and the hours slept
/// is an approximation of how long the user thinks they slept the night before
/// </summary>
class SleepLog
{
public:
	//Constructors
	SleepLog(int m = 1, int d = 1, int y = 1970, double hours = 0);

	//Methods
	bool MetSleepGoal() { return hoursSlept >= 7.5; }

	bool DateIsValid();
	void PrintSleepLog();
	
	//Getters and setters
	int GetMonth() { return month; }
	int GetDay() { return day; }
	int GetYear() { return year; }
	double GetHoursSlept() { return hoursSlept; }

	void SetHoursSlept(double hours) { if (hours > 0 && hours < 24) { hoursSlept = hours; } }
private:
	int month;
	int day;
	int year;
	double hoursSlept;

	
};

