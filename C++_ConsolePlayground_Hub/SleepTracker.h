#pragma once

#include "AppTemplate.h"
#include <vector>
#include "SleepLog.h"
#include "AppConstants.h"

enum SleepTrackerMenuOptions {
	RECORD_SLEEP_LOG = 1,
	VIEW_AVERAGE,
	PRINT_SLEEP_LOGS,
	QUIT
};

/// <summary>
/// This app is used to track how many hours of sleep I get
/// over time, and to recognize trends and suggest improvements to sleep habits
/// </summary>
class SleepTracker : AppTemplate 
{
public:
	//Constructor
	SleepTracker(std::string appID = appConsts::SLEEP_TRACKER_APP_ID, 
		std::string displayName = appConsts::SLEEP_TRACKER_DISPLAY_NAME);

	//Methods
	void RecordSleepLog();
	void DisplayMenu();
	void WriteDataToFile();
	void ReadDataFromFile();
	void PrintSleepLogs();

	//AppTemplate
	static void Startup(AppHub &hub);
	void RunApp();
private:
	//Properties
	std::vector<SleepLog> SleepData;
	int numDays;
	int firstDate;
	int lastDate;

	//Methods
	SleepLog GetDateFromUser();
	double GetHoursSleptFromUser();
};

