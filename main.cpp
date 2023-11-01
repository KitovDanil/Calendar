/*************************
* Author: Kitov D.A. *
* Date: 01.11.2023 *
* Name: Letters and two-letter combination frequency *
*************************/
#include <iostream>
#include <iomanip>

using namespace std;

// Getting month name by number
string nameOfMonth(int numberOfMonth) {
  switch(numberOfMonth) {
    case 1: return "January";
    case 2: return "February";
    case 3: return "March";
    case 4: return "April";
    case 5: return "May";
    case 6: return "June";
    case 7: return "July";
    case 8: return "August";
    case 9: return "September";
    case 10: return "October";
    case 11: return "November";
    case 12: return "December";
  }
}
// Determining if it's a leap year
bool isLeap(int year) {
  return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}
// Determining the number of days in a month
int numberOfDays(int numberOfMonth, int year) {
  switch(numberOfMonth) {
    case 1: return 31;
    case 2:
      if (isLeap(year)) {
        return 29;
      } else {
        return 28;
      }
    case 3: return 31;
    case 4: return 30;
    case 5: return 31;
    case 6: return 30;
    case 7: return 31;
    case 8: return 31;
    case 9: return 30;
    case 10: return 31;
    case 11: return 30;
    case 12: return 31;
  }
}

int main()
{
  // Input year
  int year;
  setlocale(LC_ALL, "RUS");
  cout << "Введите год: ";
  cin >> year;
  int startingDayOfWeek = 1;
  cout << endl << "Календарь для " << year << " года:" << endl << endl;

  // Calculation of the day of the week on which the year begins
  for (int curYear = 2; curYear <= year; ++curYear) {
    startingDayOfWeek = (startingDayOfWeek + 364) % 7 + 1;
    if ( isLeap(curYear - 1) ) {
      startingDayOfWeek = startingDayOfWeek % 7 + 1;
    }
  }

  // Output the calendar by months
  for (int month = 1; month <= 12; ++month) {
    if (month >= 2) {
      startingDayOfWeek = (startingDayOfWeek - 1 + numberOfDays(month - 1, year)) % 7 + 1;
    }
    cout << nameOfMonth(month) << endl << "Mon Tue Wed Thu Fri Sat Sun" << endl;
    for (int spacingIndex = 0; spacingIndex < startingDayOfWeek - 1; ++spacingIndex) {
      cout << "    ";
    }
    for (int day = 1; day <= numberOfDays(month, year); ++day) {
      cout << setw(3) << day << " ";
      if ((startingDayOfWeek + day - 1) % 7 == 0) {
        cout << endl;
      }
    }
    if (month != 12) {
      cout << endl << endl;
    }
  }

  return 0;
}
