#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

int firstDay = 3;

int daysInMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };


//Рожковская
bool leapYear(int year) {
    return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
}

//Рожковская

int firstDayOfMonth(int month, int year) {

    int firstYear = 1919;
    int totalDays = 0;
    for (firstYear; firstYear < year; firstYear++) {
        totalDays += 365;
    }
    for (int m = 1; m < month; m++) {
        if (leapYear(year)) {
            daysInMonth[1] += 1;
        }
        totalDays += daysInMonth[month - 1];
        
    }

    int result = (totalDays + firstDay) % 7;
    return result;
}
//Нечаев
void printCalendar(int month, int year) {
    string months[] = { "ЯНВАРЬ", "ФЕВРАЛЬ", "МАРТ", "АПРЕЛЬ", "МАЙ", "ИЮНЬ",
                       "ИЮЛЬ", "АВГУСТ", "СЕНТЯБРЬ", "ОКТЯБРЬ", "НОЯБРЬ", "ДЕКАБРЬ" };

    
    cout << months[month - 1] << " " << year << endl;
    cout << "ПН ВТ СР ЧТ ПТ СБ ВС" << endl;

    int startDay = firstDayOfMonth(month, year);
    int daysInCurrentMonth = daysInMonth[month - 1];

    if (leapYear(year)) {
        daysInMonth[1] += 1;
    }
    for (int i = 1; i < startDay; i++) {
        cout << "   ";
    }

    for (int day = 1; day <= daysInCurrentMonth; day++) {
        cout << setw(2) << day << " ";
        if ((day + startDay - 1) % 7 == 0) {
            cout << endl;
        }
    }
    cout << endl;
}
//Нечаев
bool validationInput(int month, int year) {

    if (cin.fail() || month < 1 || month > 12 || year < 1919 || year > 2069) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return true;
    }
    else { return false; }
}
//Нечаев

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
