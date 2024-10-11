#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

bool leapYear(int year) {
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
        return true;
    }
    else {
        return false;
    }
}

int firstDayOfMonth(int month, int year) {

    if (month == 1 || month == 2) {
        year = year - 1;
        month = month + 10;
    }
    else {
        month = month - 2;
    }

    int firstDay = (1 + ((31 * month) / 12) + year + (year / 4) - (year / 100) + (year / 400));
    int result = firstDay % 7;

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

bool validationInput(int month, int year) {

    if (cin.fail() || month < 1 || month > 12 || year < 1919 || year > 2069) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return true;
    }
    else { return false; }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int month, year;
    
    while (true) {
        cout << "Введите месяц и год: ";
        cin >> month >> year;
        if (validationInput(month,year)) {
            cout << "Некорректный ввод. Пожалуйста, введите месяц (от 1 до 12) и год (от 1919 до 2069)." << endl;
        }
        else {
            break;
        }
    }
    printCalendar(month, year);

    return 0;
}
