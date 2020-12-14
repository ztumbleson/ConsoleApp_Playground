#include "SleepTracker.h"
#include <iomanip>
#include "ConsoleHelpers.h"
#include <fstream>

SleepTracker::SleepTracker(std::string appID,
	std::string displayName) : AppTemplate(appID, displayName)
{
	numDays = 0;
	firstDate = 0;
	lastDate = 0;
}

void SleepTracker::RunApp() {
	
	int userInput = 0;
	do
	{
		DisplayMenu();
		std::cin >> userInput;

		switch (userInput) {
			case RECORD_SLEEP_LOG:
				RecordSleepLog();
				break;
			case VIEW_AVERAGE:
				//TODO Average function
				break;
			case PRINT_SLEEP_LOGS:
				PrintSleepLogs();
				break;
			default:
				break;
		}
	} while (userInput != QUIT);

	WriteDataToFile();
}

void SleepTracker::Startup(AppHub& hub) {
	SleepTracker* sleepTrackerApp = new SleepTracker();
	hub.RegisterApp(sleepTrackerApp);

	sleepTrackerApp->ReadDataFromFile();
}

void SleepTracker::RecordSleepLog() {
	//Get the date for the sleep log
	SleepLog newLog = GetDateFromUser();

	//Get the number of hours slept
	double hours = GetHoursSleptFromUser();
	
	//Set sleep hours
	newLog.SetHoursSlept(hours);

	//Add to sleep data
	SleepData.push_back(newLog);
}

/// <summary>
/// Dipsplay the menu for the sleep tracker
/// </summary>
void SleepTracker::DisplayMenu() {
	std::cout << "\n\nSleep Tracker Menu\n"
		<< ConsoleHelpers::PrintAsteriskLine(20)
		<< "\n1.) Record new Sleep Log\n"
		<< "2.) View average sleep hours\n"
		<< "3.) Print all current sleep logs\n"
		<< "4.) Quit\n"
		<< ConsoleHelpers::PrintAsteriskLine(20) << std::endl;

	std::cout << "Select a menu option by entering the corresponding number and pressing enter.\n";
	std::cout << "Enter a menu option: ";
}

void SleepTracker::PrintSleepLogs() {
	std::vector<SleepLog>::iterator sleepIter = SleepData.begin();
	std::cout << "Compiled sleep data, over a total of " << SleepData.size() << " days: \n";
	for (sleepIter; sleepIter != SleepData.end(); sleepIter++) {
		sleepIter->PrintSleepLog();
	}
}

/// <summary>
/// This method handles user dialogue for getting the date for a new sleep log
/// from the user via the console
/// </summary>
/// <returns></returns>
SleepLog SleepTracker::GetDateFromUser() 
{
	//Local variables
	std::string todayDate = "";
	std::string dateConfirm = "";
	bool dateValid = false;
	int month = 1;
	int day = 1;
	int year = 1970;
	SleepLog newLog;

	while (!dateValid || (dateConfirm != "y" && dateConfirm != "Y"))
	{
		//Get the date
		dateValid = false;
		std::cout << "Please enter today's date in the format (MM/DD/YYYY)."
			<< std::endl << "Today's date: ";
		std::cin >> todayDate;

		try {
			//Parse date ints from date string
			month = std::stoi(todayDate.substr(0, 2));
			day = std::stoi(todayDate.substr(3, 2));
			year = std::stoi(todayDate.substr(6, 4));
		}
		catch (...) {
			std::cout << "\nError: The date you entered cannot be recognized.\n" << std::endl;
			continue;
		}
		
		newLog = SleepLog(month, day, year);
		if (newLog.DateIsValid()) {
			//Date was parsed successfully
			dateValid = true;

			std::cout << "You entered " << month << "/" << std::setfill('0') << std::setw(2) << day;
			std::cout << "/" << year << " as the date." << std::endl;
			std::cout << "Is that correct? (y/n): ";
			std::cin >> dateConfirm;
		}
	}

	return newLog;
}

double SleepTracker::GetHoursSleptFromUser() {
	double hours;
	
	std::cout << "Please enter the number hours slept:\n"
		<< "Hours slept: ";
	std::cin >> hours;

	//TODO input validation
	return hours;
}

void SleepTracker::ReadDataFromFile() {
	int month;
	int day; 
	int year;
	double hoursSlept;
	std::string dateText;

	std::ifstream inFile;
	inFile.open("SleepData.txt");

	std::vector<SleepLog>::iterator sleepIter = SleepData.begin();
	while(!inFile.eof()){
		inFile >> dateText >> month >> day >> year >> hoursSlept;
		SleepLog logFromFile = SleepLog(month, day, year, hoursSlept);
		SleepData.push_back(logFromFile);
	}

	inFile.close();
}

void SleepTracker::WriteDataToFile() {
	std::ofstream outFile;
	outFile.open("SleepData.txt");
	outFile.clear();

	std::vector<SleepLog>::iterator sleepIter = SleepData.begin();
	for (sleepIter; sleepIter != SleepData.end(); sleepIter++) {
		outFile << "Date: " << sleepIter->GetMonth() << " "
			<< sleepIter->GetDay() << " " << sleepIter->GetYear()
			<< " " << sleepIter->GetHoursSlept() << std::endl;
	}

	outFile.close();
}


