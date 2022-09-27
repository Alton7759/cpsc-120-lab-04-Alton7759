// TODO: Add the required header

// Program to convert decimalized feet to feet, inches, and fractional inches,
// up to one eigth.

#include <cmath>
#include <iostream>

using namespace std;

// TODO: Define a constant of type float with the name kInchesInFeet
// which is assigned the value 12.0

// TODO: Define a constant of type float with the name kEighthsInInch
// which is assigned the value 8.0

// Main function - the entry point to our program, it does not take command line
// arguments
int main(int argc, char const *argv[]) {

  // TODO: Declare a variable of type float with the name input_decimal_feet and
  // assign NAN to it.

  // TODO: Prompt the computer user to enter the number of feet to convert. See
  // the README.md for examples.

  // TODO: Read from the terminal using cin to set input_decimal_feet to the
  // input

  // TODO: Declare a variable named sign of type string. You do
  // not need to initialize strings because they are set to an empty string by
  // default. An empty string is "".

  // TODO: Using input_decimal_feet, write an if statement. If
  // input_decimal_feet is less than 0.0, then multiply input_decimal_feet by
  // -1.0 and assign the result back to input_decimal_feet. Assign the variable
  // sign the string "-". (Else, do nothing - you do not need an else or else if
  // statement.)

  // TODO: Declare a variable of type int with the name _feet_integer_component
  // and assign 0 to it.

  // TODO: Declare a variable of type float with the name
  // feet_fractional_component and assign NAN to it.

  // TODO: Using the explanation in the README.md, truncate input_decimal_feet
  // and assign the result to _feet_integer_component. For example:
  //  _feet_integer_component = static_cast<int>(input_decimal_feet);

  // TODO: Using the explanation in the README.md, take the difference between
  // input_decimal_feet and _feet_integer_component and assign it to
  // feet_fractional_component
  // For example:
  // feet_fractional_component = input_decimal_feet -
  // float(_feet_integer_component);

  // TODO Optional: You may want to print out your values at this point to
  // verify that things are working as you expect. Remember to remove any extra
  // print statements when you have your program working to your satisfaction.

  // TODO: Declare a variable of type float with the name decimal_inches and
  // assign NAN to it.

  // TODO: Multiply feet_fractional_component by kInchesInFeet and assign it to
  // decimal_inches.

  // TODO: Declare a variable of type int with the name
  // _inches_integer_component and assign 0 to it.

  // TODO: Declare a variable of type float with the name
  // inches_fractional_component and assign NAN to it.

  // TODO: Using the explanation in the README.md, truncate decimal_inches and
  // assign the result to _inches_integer_component.

  // TODO: Using the explanation in the README.md, take the difference between
  // decimal_inches and _inches_integer_component and assign it to
  // inches_fractional_component

  // TODO Optional: You may want to print out your values again at this point to
  // verify that things are working as you expect. Remember to remove any extra
  // print statements when you have your program working to your satisfaction.

  // TODO: Declare a variable of type float with the name eighths and
  // assign NAN to it.
  // TODO: Multiply inches_fractional_component by kEightsInInch and assign it
  // to eighths.

  // TODO: Declare a variable of type int with the name
  // _eighths_integer_component and assign 0 to it.

  // TODO: Using the explanation in the README.md, truncate eighths and
  // assign the result to _eighths_integer_component.

  // TODO: Using cout, print to the the terminal the sign and
  // input_decimal_feet.

  // TODO: Using cout, print the sign and the _feet_integer_component.

  // TODO: Write and if statement. If eighths_integer_component != 0, then,
  // using cout, print out eighths_integer_component along with the string "/8"
  // to make it look like a fraction.

  // TODO: Using cout, print "inches\n" to terminate the string.

  return 0;
}