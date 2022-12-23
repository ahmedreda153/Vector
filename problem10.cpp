#include <iostream>
#include <string>
#include <vector>
using namespace std;

class MonthError
{
};

class DayError
{
};

int main()
{
    try
    {
        int day, month, first;
        vector<string> months = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
        // vector<int>days={31,29,31,30,31,30,31,31,30,31,30,31};
        cout << "Enter your date: ";
        string date;
        cin >> date;
        first = date.find("/");
        day = stoi(date.substr(0, first)); // lw el day 01 by5alo 1 why??????????
        month = stoi(date.substr(first + 1, -1));
        if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && (day < 1 || day > 31))
        {
            throw DayError();
        }
        if ((month == 4 || month == 6 || month == 9 || month == 11) && (day < 1 || day > 30))
        {
            throw DayError();
        }
        if ((month == 2) && (day < 1 || day > 29))
        {
            throw DayError();
        }
        if (month < 1 || month > 12)
        {
            throw MonthError();
        }
        cout << "The converted date: " << months[month - 1] << " " << day;
    }

    catch (DayError)
    {
        cout << "Invalid day";
    }
    catch (MonthError)
    {
        cout << "Invalid month";
    }
}
