# C++ Date Library

A C++ library for working with dates and date periods. This project implements two classes, `clsDate` and `clsPeriod`, to perform date calculations, generate calendars, compare dates, and manage date ranges.

The project is built using object-oriented programming principles and provides both static and instance methods for many date operations.

## Features

### 1. Date Management — `clsDate`

The `clsDate` class represents a date using three components:

- `Day`
- `Month`
- `Year`

It provides constructors for creating dates from individual components, a date string, or a day number within a year.

#### Creating Dates

The library supports the following construction methods:

```cpp
clsDate Date1(28, 10, 2026);   // Day, month, year
clsDate Date2("28/10/2026");   // Date string
clsDate Date3(301, 2026);      // Day number, year
```

### 2. Leap Years and Calendar Calculations

The library provides functions for determining leap years and calculating calendar information.

- `isLeapYear()` — Determines whether a year is a leap year.
- `DaysInYear()` — Returns the number of days in a year.
- `CountDaysInMonth()` — Returns the number of days in a given month.
- `countNumHours()` — Converts days into hours.
- `countNumMinutes()` — Converts hours into minutes.
- `countNumSeconds()` — Converts minutes into seconds.

### 3. Calendar Generation

Generate calendar layouts for individual months or entire years.

- `MonthCalender()` — Displays a monthly calendar.
- `yearCalender()` — Displays all 12 months of a year.
- `printMonthName()` — Prints a month's abbreviated name.
- `printDaysRow()` — Prints the weekday headings.

### 4. Date Comparisons

Compare two dates to determine their chronological order.

- `isDate1BeforeDate2()` — Checks whether the first date is before the second.
- `isDate1AfterDate2()` — Checks whether the first date is after the second.
- `isDate1EqualDate2()` — Checks whether two dates are equal.
- `CompareTwoDates()` — Returns an enumeration indicating whether the first date is before, equal to, or after the second.

The comparison results are represented by:

```cpp
enum enCompareDate {
    After = 1,
    Equal = 0,
    Before = -1
};
```

### 5. Date Arithmetic

Perform calculations and move between dates.

- `increaseDateBy1()` — Advances a date by one day.
- `increaseDateByDaysShort()` — Advances a date by a specified number of days.
- `DaysUpToDate()` — Calculates the day number within a year.
- `DaysToFullDate()` — Calculates the number of days from the beginning of year 1 to the specified date.
- `differenceInDays()` — Calculates the number of days between two dates.
- `differenceInDaysGeneral()` — Calculates the signed difference between two dates.

### 6. Date Conversion and Formatting

Convert dates between strings and date objects.

- `stringToDate()` — Converts a date string into a `clsDate` object.
- `DateToString()` — Converts a date into a string in `DD/MM/YYYY`-style format.
- `dateFormat()` — Formats a date using `dd`, `mm`, and `yyyy` placeholders.
- `daysToDate()` — Converts a day number within a year into a printed date.

**Example:**

```cpp
clsDate Date("28/10/2026");

cout << clsDate::DateToString(Date);
```

Expected output:

```text
28/10/2026
```

### 7. Weekday Calculations

Determine the weekday corresponding to a date.

- `getDayWekOrd()` — Calculates the weekday index.
- `shortDayName()` — Returns the abbreviated weekday name.
- `printDate()` — Displays a date alongside its weekday.

The weekday index follows this order:

| Index | Day |
|---:|---|
| 0 | Sunday |
| 1 | Monday |
| 2 | Tuesday |
| 3 | Wednesday |
| 4 | Thursday |
| 5 | Friday |
| 6 | Saturday |

### 8. Working with Date Periods — `clsPeriod`

The `clsPeriod` class represents a period using a start date and an end date.

It provides functionality for analyzing date ranges.

- `IsOverlap()` — Checks whether two periods overlap.
- `countOverlapedDays()` — Calculates the difference in days between the overlapping boundaries.
- `CountPeriodLength()` — Calculates the difference in days between the start and end dates.
- `IsDateInPeriod()` — Checks whether a date falls within a period.

These operations are useful for applications involving date ranges, scheduling, and time interval calculations.

## Example Usage

The following example demonstrates basic date operations using `clsDate`.

```cpp
#include <iostream>
#include "clsDate.cpp"

using namespace std;

int main() {
    clsDate Date1(28, 10, 2026);
    clsDate Date2("01/11/2026");

    Date1.printDate();

    cout << "Date 1: "
         << clsDate::DateToString(Date1) << endl;

    cout << "Days between dates: "
         << clsDate::differenceInDays(Date1, Date2)
         << endl;

    Date1.increaseDateBy1();

    cout << "Next date: "
         << clsDate::DateToString(Date1) << endl;

    return 0;
}
```

*Note: Adjust the include statement to match your project structure. In a conventional library layout, the class declaration would be placed in a header file, with implementations in a separate source file.*

## Technologies Used

- **Language:** C++
- **Standard Library:** `<iostream>`, `<string>`, `<vector>`, and `<iomanip>`
- **Concepts:** Classes, encapsulation, static member functions, constructors, method overloading, and enumerations.



The current implementation contains both date-related classes in the same source file.

## Potential Applications

This library can serve as a foundation for:

- Calendar applications.
- Date comparison and calculation utilities.
- Scheduling systems.
- Date-range and interval analysis.
- C++ object-oriented programming practice.

