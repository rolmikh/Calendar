
#include <iostream>

using namespace std;

int firstDay = 2; //первый день 1919 года


bool leapYear(int year) {
	cin >> year;

	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
		return true;
	}
	else
	{
		return false;
	}
}

int firstDayOfMonth(int month, int year) {

	int firstYear = 1919;

	int totalDays = 0;

	for (firstYear; firstYear < year; firstYear++) {
		totalDays += 365;
	}
	for (int m = 1; m < month; m++) {
		if (month == 2) {
			if (leapYear(year)) {
				totalDays += 29;
			}
			else {
				totalDays += 28;
			}
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11) {
			totalDays += 30;
		}
		else {
			totalDays += 31;
		}
	}

	

	int result = (totalDays + firstDay) % 7;

	return result;


}

int main()
{
	int month, year;
	cin >> month >> year;

	cout << firstDayOfMonth(month, year) << endl;

	return 0;
}
