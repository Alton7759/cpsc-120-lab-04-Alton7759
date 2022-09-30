// Christian Alton bonilla
// CPSC 120-01
// 2022-09-21
// Alton77@csu.fullerton.edu
// @alton7759
//
// Lab 04-01
// Partners: @taco
//
// Program to calculate the number of days between two Gregorian dates.
//

#include <iostream>

using namespace std;
int main(int argc, char const *argv[]) {
  cout << "Let's find the number of days between two dates...\n";
  int start_month{0};
  cout << "Enter a start month: ";
  cin >> start_month;
  int start_day{0};
  cout << "Enter a start day: ";
  cin >> start_day;
  int start_year{0};
  cout << "Enter a start year: ";
  cin >> start_year;
  int start_number_of_days_since_epoch{
      start_day - 32075 +
      1461 * (start_year + 4800 + (start_month - 14) / 12) / 4 +
      367 * (start_month - 2 - (start_month - 14) / 12 * 12) / 12 -
      3 * ((start_year + 4900 + (start_month - 14) / 12) / 100) / 4};
  int end_month{0};
  cout << "Enter an end month: ";
  cin >> end_month;
  int end_day{0};
  cout << "Enter an end day: ";
  cin >> end_day;
  int end_year{0};
  cout << "Enter an end year: ";
  cin >> end_year;
  int end_number_of_days_since_epoch{
      end_day - 32075 + 1461 * (end_year + 4800 + (end_month - 14) / 12) / 4 +
      367 * (end_month - 2 - (end_month - 14) / 12 * 12) / 12 -
      3 * ((end_year + 4900 + (end_month - 14) / 12) / 100) / 4};
  int number_days{end_number_of_days_since_epoch -
                  start_number_of_days_since_epoch};
  cout << "The number of days between " << start_month << "/" << start_day
       << "/" << start_year << " and " << end_month << "/" << end_day << "/"
       << end_year << " is " << number_days << " days\n";
  return 0;
}