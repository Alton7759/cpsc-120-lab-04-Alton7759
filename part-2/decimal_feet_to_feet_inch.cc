// Christian Alton bonilla
// CPSC 120-01
// 2022-09-21
// Alton77@csu.fullerton.edu
// @alton7759
//
// Lab 04-01
// Partners: @taco
//
// Program to convert decimalized feet to feet, inches, and fractional inches,
// up to one eigth.
#include <cmath>
#include <iostream>

using namespace std;
double k_inches_in_feet = 12.0;
double k_eighths_in_inch = 8.0;
int main(int argc, char const *argv[]) {
  double input_decimal_feet = NAN;
  cout << "Enter the number of feet you wish to convert to feet-inch: ";
  cin >> input_decimal_feet;
  string sign;
  if (input_decimal_feet < 0.0) {
    input_decimal_feet = input_decimal_feet * -1.0;
    sign = "-";
  }
  int feet_integer_component = 0;
  double feet_fractional_component = NAN;
  feet_integer_component = static_cast<int>(trunc(input_decimal_feet));
  feet_fractional_component = input_decimal_feet - feet_integer_component;
  double decimal_inches = NAN;
  decimal_inches = feet_fractional_component * k_inches_in_feet;
  int inches_integer_component = 0;
  double inches_fractional_component = NAN;
  inches_integer_component = static_cast<int>(trunc(decimal_inches));
  inches_fractional_component = decimal_inches - inches_integer_component;
  double eighths = NAN;
  eighths = inches_fractional_component * k_eighths_in_inch;
  int eighths_integer_component = 0;
  eighths_integer_component = static_cast<int>(trunc(eighths));
  cout << sign << input_decimal_feet;
  cout << " feet is " << sign << feet_integer_component << " feet, ";
  cout << inches_integer_component << " ";
  if (eighths_integer_component != 0) {
    cout << "and " << eighths_integer_component << "/8 ";
  }
  cout << "inches\n";
  return 0;
}