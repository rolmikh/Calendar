#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

int firstDay = 3; // первый день 1919 года

bool leapYear(int year) {
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
        return true;
    }
    else {
        return false;
    }
}

int firstDayOfMonth(int month, int year) {
    int firstYear = 1919;
    int totalDays = 0;

    for (int y = firstYear; y < year; y++) {
        if (leapYear(y)) {
            totalDays += 366;
        }
        else {
            totalDays += 365;
        }
    }

    for (int m = 1; m < month; m++) {
        if (m == 2) {
            if (leapYear(year)) {
                totalDays += 29;
            }
            else {
                totalDays += 28;
            }
        }
        else if (m == 4 || m == 6 || m == 9 || m == 11) {
            totalDays += 30;
        }
        else {
            totalDays += 31;
        }
    }

    int result = (totalDays + firstDay) % 7;
    if (result == 0) {
        result = 7;
    }
    return result;
}

void printCalendar(int month, int year) {
    string months[] = { "ЯНВАРЬ", "ФЕВРАЛЬ", "МАРТ", "АПРЕЛЬ", "МАЙ", "ИЮНЬ",
                       "ИЮЛЬ", "АВГУСТ", "СЕНТЯБРЬ", "ОКТЯБРЬ", "НОЯБРЬ", "ДЕКАБРЬ" };

    cout << months[month - 1] << " " << year << endl;
    cout << "ПН ВТ СР ЧТ ПТ СБ ВС" << endl;

    int startDay = firstDayOfMonth(month, year);

    int daysInMonth;
    if (month == 2) {
        if (leapYear(year)) {
            daysInMonth = 29;
        }
        else {
            daysInMonth = 28;
        }
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        daysInMonth = 30;
    }
    else {
        daysInMonth = 31;
    }

    for (int i = 1; i < startDay; i++) {
        cout << "   ";
    }

    for (int day = 1; day <= daysInMonth; day++) {
        cout << setw(2) << day << " ";
        if ((day + startDay - 1) % 7 == 0) {
            cout << endl;
        }
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int month, year;
    while (true) {
        cout << "Введите месяц и год: ";
        cin >> month >> year;

        if (cin.fail() || month < 1 || month > 12 || year < 1919 || year > 2069) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Некорректный ввод. Пожалуйста, введите месяц (1-12) и год (1919-2069)." << endl;
        }
        else { break; }
    }
    
    printCalendar(month, year);

    return 0;
}
