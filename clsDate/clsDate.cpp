// clsDate.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

enum enCompareDate { After = 1, Equal = 0, Before = -1 };

class clsDate {
    short _day;
    short _month;
    int _year;

public:
    static bool isLeapYear(int Num) {
        return ((Num % 4 == 0 && Num % 100 != 0) || (Num % 400 == 0));
    }

    static int DaysInYear(bool isLeap) {
        if (isLeap) {
            return 366;
        }
        else {
            return 365;
        }
    }
    static short CountDaysInMonth(bool isLeap, short NumMonth) {
        short Months_31[] = { 1,3,5,7,8,10,12 };
        if (NumMonth == 2) {
            if (isLeap)
                return 29;
            else
                return 28;
        }
        for (short Month : Months_31) {
            if (Month == NumMonth) {
                return 31;
            }
        }
        return 30;
    }
    static short CountDaysInMonthOne(bool isLeap, short NumMonth) {
        int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
        return (NumMonth == 2) ? (isLeap ? 29 : 28) : days[NumMonth - 1];

    }
    static int countNumHours(int days) {
        return days * 24;
    }
    static int countNumMinutes(int Hours) {
        return Hours * 60;
    }
    static int countNumSeconds(int Minutes) {
        return Minutes * 60;
    }
    static int CountReadNumber(string message) {
        cout << message;
        int Num;
        cin >> Num;
        return Num;
    }
    static string shortDayName(int d) {
        string days[7] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
        return days[d];
    }

    static int getDayWekOrd(clsDate date) {

        int a = (14 - date._month) / 12;
        int y = date._year - a;
        int m = date._month + 12 * a - 2;
        int d = (date._day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

        return d;
    }
    int getDayWekOrd() {

        int a = (14 - _month) / 12;
        int y = _year - a;
        int m = _month + 12 * a - 2;
        int d = (_day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

        return d;
    }

    static void printMonthName(short month) {
        string shortMonths[12] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
        cout << "\n_____________" << shortMonths[month - 1] << "____________\n";
    }
    void printMonthName(){
        printMonthName(_month);
    }
    static void printDaysRow() {
        cout << "\n" << setw(4) << "Sun" << setw(4) << "Mon" << setw(4) << "Tue" << setw(4) << "Wed"
            << setw(4) << "Thu" << setw(4) << "Fri" << setw(4) << "Sat" << "\n";
    }
    static void MonthCalender(short month, int year) {
        clsDate date;
        date._year = year;
        date._month = month;
        int DayOrd = 0, daysInMonth = 0;
        string emptyspace = "    ";
        bool isLeap = isLeapYear(date._year);
        daysInMonth = CountDaysInMonth(isLeap, date._month);
        DayOrd = getDayWekOrd(date);
        printMonthName(month);
        printDaysRow();

        for (int i = 0; i < DayOrd; i++) {
            cout << "    ";
        }
        for (short i = 1; i <= daysInMonth; i++) {
            cout << setw(4) << i;

            if (DayOrd == 6)
                cout << "\n";
            DayOrd += 1;
            DayOrd = DayOrd % 7;
        }
        cout << "\n____________________________\n";

    }
    void MonthCalender() {
        MonthCalender(_month, _year);
    }

    static void yearCalender(int year) {
        clsDate date;
        date._year = year;
        for (short i = 1; i <= 12; i++) {
            date._month = i;
            MonthCalender(date._month, date._year);
        }
    }
    void yearCalender() {
        yearCalender(_year);
    }

    static int DaysUpToDate(clsDate date) {
        bool Isleap = isLeapYear(date._year);
        int days = 0;
        for (short i = 1; i < date._month; i++) {

            days += CountDaysInMonthOne(Isleap, i);
        }
        days += date._day;
        return days;
    }
    int DaysUpToDate() {
        DaysUpToDate(*this);
    }

    static void daysToDate(int days, int year) {
        short months = 1;
        bool is_leap = isLeapYear(year);
        while (CountDaysInMonthOne(is_leap, months) < days) {
            days = days - CountDaysInMonthOne(is_leap, months);
            months += 1;
        }
        cout << "\n" << days << "/" << months << "/" << year << "\n";
    }

    static clsDate increaseDateByDaysShort(clsDate CurrentDate, int days) {
        int remainingDays = DaysUpToDate(CurrentDate) + days;
        clsDate NewDate;
        NewDate._day = 1;
        NewDate._month = 1;
        NewDate._year = CurrentDate._year;

        short daysInMonth = CountDaysInMonth(isLeapYear(NewDate._year), NewDate._month);
        while (true) {
            if (daysInMonth < remainingDays) {
                NewDate._month++;
                if (NewDate._month == 12) {
                    NewDate._year++;
                    NewDate._month = 1;
                }
                remainingDays = remainingDays - daysInMonth;
                daysInMonth = CountDaysInMonth(isLeapYear(NewDate._year), NewDate._month);

            }
            else {
                NewDate._day = remainingDays;
                break;
            }
        }

        return NewDate;


    }
    void increaseDateByDaysShort(int days) {
        int remainingDays = DaysUpToDate(*this) + days;
        clsDate NewDate;
        NewDate._day = 1;
        NewDate._month = 1;
        NewDate._year = this->_year;

        short daysInMonth = CountDaysInMonth(isLeapYear(NewDate._year), NewDate._month);
        while (true) {
            if (daysInMonth < remainingDays) {
                NewDate._month++;
                if (NewDate._month == 12) {
                    NewDate._year++;
                    NewDate._month = 1;
                }
                remainingDays = remainingDays - daysInMonth;
                daysInMonth = CountDaysInMonth(isLeapYear(NewDate._year), NewDate._month);

            }
            else {
                NewDate._day = remainingDays;
                break;
            }
        }

        this->_day = NewDate._day;
        this->_month = NewDate._month;
        this->_year= NewDate._year;

    }


    static bool isDate1BeforeDate2(clsDate Date1, clsDate Date2) {
        if (Date1._year < Date2._year) {
            return true;
        }
        else if (Date1._month < Date2._month && (Date1._year <= Date2._year)) {
            return true;
        }
        else if (Date1._day < Date2._day && (Date1._month <= Date2._month) && (Date1._year <= Date2._year)) {
            return true;
        }
        else return false;
    }
    bool isDateBeforeDate2(clsDate Date2) {
        return isDate1BeforeDate2(*this, Date2);
    }

    static bool isDate1EqualDate2(clsDate Date1, clsDate Date2) {
        return (Date1._year == Date2._year) ? (Date1._month == Date2._month) ? Date1._day == Date2._day ? true : false : false : false;
    }
    bool isDateEqualDate2(clsDate Date2) {
        return isDate1EqualDate2(*this, Date2);
    }

    static bool isLastDay(clsDate date) {
        return date._day == CountDaysInMonth(isLeapYear(date._year), date._month);

    }
    bool isLastDay() {
        isLastDay(*this);
    }

    static bool isLastMonth(clsDate date) {
        return (date._month == 12) ? true : false;
    }
    bool isLastMonth() {
        isLastMonth(*this);
    }

    static clsDate increaseDateBy1(clsDate date) {
        clsDate NewDate = date;
        short MonthDays = CountDaysInMonth(isLeapYear(date._year), date._month);
        if (date._day == MonthDays) {
            if (date._month == 12) {
                NewDate._year++;
                NewDate._month = 1;
                NewDate._day = 1;

            }
            else {
                NewDate._month++;
                NewDate._day = 1;
            }
        }
        else {
            NewDate._day++;
        }
        return NewDate;
    }
    void increaseDateBy1() {
        short MonthDays = CountDaysInMonth(isLeapYear(_year), _month);
        if (_day == MonthDays) {
            if (_month == 12) {
                _year++;
                _month = 1;
                _day = 1;

            }
            else {
                _month++;
                _day = 1;
            }
        }
        else {
            _day++;
        }
    }
    static void printDate(clsDate date) {
        string days[7] = { "Sunday","Monday","Tuesday","Wednesday","Thursday","FriDay","Saturday" };
        short DayOrd = getDayWekOrd(date);
        cout << "\n" << "Today is " << days[DayOrd] << " ," << date._day << "/" << date._month << "/" << date._year << "\n";
    }
    void printDate() {
        printDate(*this);
    }

    static int DaysToFullDate(clsDate date) {
        int dateDays = DaysUpToDate(date);
        for (int i = 1; i < date._year; i++) {
            for (short j = 1; j <= 12; j++) {
                dateDays += CountDaysInMonth(isLeapYear(i), j);
            }

        }
        return dateDays;
    }

    static int differenceInDays(clsDate date1, clsDate date2) {
        int days = 0;
        while (isDate1BeforeDate2(date1, date2)) {
            date1 = increaseDateBy1(date1);
            days++;

        }
        return days;
    }
    int differenceInDays(clsDate date2) {
        return differenceInDays(*this, date2);
    }


    static int differenceInDaysGeneral(clsDate date1, clsDate date2) {
        int days = 0;
        while (isDate1BeforeDate2(date1, date2)) {
            date1 = increaseDateBy1(date1);
            days++;

        }
        while (isDate1BeforeDate2(date2, date1)) {
            date2 = increaseDateBy1(date2);
            days--;

        }
        return days;


    }
    static clsDate GetSystemDate() {
        clsDate Date;
        time_t t = time(0);
        tm now;
        localtime_s(&now, &t);
        Date._year = now.tm_year + 1900;
        Date._month = now.tm_mon + 1;
        Date._day = now.tm_mday;
        return Date;
    }

    static bool isDate1AfterDate2(clsDate Date1, clsDate Date2) {
        return (!isDate1BeforeDate2(Date1, Date2)) && isDate1EqualDate2(Date1, Date2);
    }

    static enCompareDate CompareTwoDates(clsDate Date1, clsDate Date2) {
        return (isDate1BeforeDate2(Date1, Date2)) ? enCompareDate::Before : isDate1EqualDate2(Date1, Date2) ? enCompareDate::Equal : enCompareDate::After;
    }
    enCompareDate CompareTwoDates(clsDate Date2) {
        return CompareTwoDates(*this, Date2);
    }


    static bool isValidateDate(clsDate date) {
        short daysInMonth = CountDaysInMonth(isLeapYear(date._year), date._month);
        if (date._day > daysInMonth || date._day < 1) {
            return false;
        }
        if (date._month > 12 || date._day < 1) {
            return false;
        }
        else {
            return true;
        }
    }
    bool isValidateDate() {
        isValidateDate(*this);
    }

    static string ReadStringDate(string message) {
        string date;
        cout << message;
        getline(cin >> ws, date);
        return date;


    }
    static vector<string> split(string s, string delimiter)
    {
        vector<string> words;
        int pos;

        while ((pos = s.find(delimiter)) != string::npos)
        {
            if (pos > 0)
                words.push_back(s.substr(0, pos));

            s.erase(0, pos + delimiter.length());
        }

        if (!s.empty())
            words.push_back(s);

        return words;
    }
    static clsDate stringToDate(string dateString) {
        vector<string> Vdate = split(dateString, "/");

        clsDate date;
        date._day = stoi(Vdate[0]);
        date._month = stoi(Vdate[1]);
        date._year = stoi(Vdate[2]);
        return date;

    }

    static string DateToString(clsDate date) {
        string dateStrinng;
        dateStrinng += to_string(date._day) + "/";
        dateStrinng += to_string(date._month) + "/";
        dateStrinng += to_string(date._year);
        return dateStrinng;
    }
    string DateToString() {
        DateToString(*this);
    }
    static string dateFormat(clsDate date, string format) {
        string dateString = format;
        int position;
        position = dateString.find("dd");
        dateString.replace(position, 2, to_string(date._day));

        position = dateString.find("mm");
        dateString.replace(position, 2, to_string(date._month));

        position = dateString.find("yyyy");
        dateString.replace(position, 4, to_string(date._year));
        return dateString;
    }



    clsDate(string dateString) {
        vector<string> Vdate = split(dateString, "/");
        _day = stoi(Vdate[0]);
        _month= stoi(Vdate[1]);
        _year = stoi(Vdate[2]);

    }
    clsDate(short day, short month,int year) {
        _day = day;
        _month = month;
        _year = year;
    }
    clsDate(int days, int year) {
        short months = 1;
        bool is_leap = isLeapYear(year);
        while (CountDaysInMonthOne(is_leap, months) < days) {
            days = days - CountDaysInMonthOne(is_leap, months);
            months += 1;
        }
        _year = year;
        _month = months;
        _day = days;

    }
    clsDate() {
    }
};

class clsPeriod {
    clsDate StartDate;
    clsDate EndDate;

    static bool IsOverlap(clsPeriod Period1, clsPeriod Period2) {
    enCompareDate ComparingPeriod1Start = clsDate::CompareTwoDates(Period1.StartDate, Period2.EndDate);
    enCompareDate ComparingPeriod1End = clsDate::CompareTwoDates(Period1.EndDate, Period2.StartDate);
    if (ComparingPeriod1Start == 1 || ComparingPeriod1End == -1) {
        return false;
    }
    else {
        return true;
    }
}
static int countOverlapedDays(clsPeriod period1, clsPeriod period2) {
    int days;
    if (IsOverlap(period1, period2)) {
        clsDate startDate;
        clsDate endDate;
        enCompareDate biggerStart = clsDate::CompareTwoDates(period1.StartDate, period2.StartDate);
        if (biggerStart == 1) {
            startDate = period1.StartDate;
        }
        else if (biggerStart == -1) {
            startDate = period2.StartDate;
        }
        enCompareDate biggerEnd = clsDate::CompareTwoDates(period1.EndDate, period2.EndDate);
        if (biggerEnd == -1) {
            endDate = period1.EndDate;
        }
        else if (biggerEnd == 1) {
            endDate = period2.EndDate;
        }
        days = clsDate::differenceInDays(startDate, endDate);

        return days;
    }
    return 0;
}
int countOverlapedDays( clsPeriod period2) {
    return countOverlapedDays(*this, period2);
}
static int CountPeriodLength(clsPeriod period, bool includeLastday = false) {
    return clsDate::differenceInDays(period.StartDate, period.EndDate);

}
int CountPeriodLength( bool includeLastday = false) {
    return CountPeriodLength(*this, includeLastday);
}
static bool IsDateInPeriod(clsPeriod period, clsDate date) {

    while (clsDate::isDate1BeforeDate2(period.StartDate, period.EndDate)) {
        if (clsDate::isDate1EqualDate2(date, period.StartDate)) {
            return true;

        }
        period.StartDate = clsDate::increaseDateBy1(period.StartDate);
    }
    return false;
}
bool IsDateInPeriod( clsDate date) {
    IsDateInPeriod(*this, date);
}
};
int main()
{
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
