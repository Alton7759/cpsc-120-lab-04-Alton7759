
# Decimal Feet to Feet & Inches

When working with [US Customary Units](https://en.wikipedia.org/wiki/United_States_customary_units), one quickly realizes that they don't work well in decimal. Unlike the [International System of Units](https://en.wikipedia.org/wiki/International_System_of_Units), commonly referred to as the metric system, the US customary units are not base 10. Since they are not expressed in a base 10 counting system having 2.34 feet is really 2 feet 4 inches (2'4") and 3.6 feet is 3 feet 7 and 1/8 inches.

We are interested in doing a little arts & crafts at home and we've made measurements of a project that we're going to build out of wood. Using our handy dandy [TI calculator](https://en.wikipedia.org/wiki/Comparison_of_Texas_Instruments_graphing_calculators), we've marked up our plans with very precise measurements out to seven decimal places!

Regrettably, our tape measure and ruler only go to eighths of inches or 0.125 inches. We need to write a program that can convert our measurements in decimal to feet, inches, and eighths of inches. ([What's the difference between a carpenter and a woodworker?](.answer.md))

The challenge here is that if you have a number like 123.45, how do you separate the fractional part (0.45) from the integer part (123)?

A very poor way to do this is to somehow truncate (cut) the decimal number 123.45 to just 123 and then subtract 123 from 123.45. For example, in C++ one may write something like this:

```C++
	float decimal_number{123.45};
	int truncated = static_cast<int>(decimal_number);
	float fractional_part = decimal_number - float(truncated);
```

Another way to achieve the same ends is to use the math library's [`trunc()`](https://en.cppreference.com/w/c/numeric/math/trunc) function to compute the nearest integer.

```C++
    float decimal_number{123.45};
    int truncated = static_cast<int>(trunc(decimal_number));
    float fractional_part = decimal_number - truncated;
```

For CPSC 120, either approach is a good approach and will earn you full credit for this assignment. The given approachs to change a decimal number to an integer are not a very good way strategies for many reasons. (Can you think of one reason?) However for this exercise, you may use either approach if you can't think of a better way to separate out the integer part from the fractional part. (What would happen if `decimal_number` was a very, very large number; would the casting to an `int` type work as we expect? Would `trunc()` return a value that can be converted to an `int`?)

Remember the types must always match. Look at each line with an assignment operator ('='). Notice that the type on the left hand side matches the type on the right hand side. When we want to assign a floating point number like a `float` or `double` to an integer variable (of type `int`), then we can use the [`static_cast` operation](https://en.cppreference.com/w/cpp/language/static_cast) to tell the compiler to treat something of one type as another type.

Once you have the two parts separated, you can figure out how many inches there are because you know that there are 12 inches to every foot. Given our example, 12 × 0.45 is 5.4 inches. Again, we have to separate out the integer part from the fractional part to find out how many eighths of an inch there are. We know there are 8 eighths of an inch in every inch so 0.4 × 8 is 3.2 eighths of an inch.

Since our tape measure and ruler can't go any finer than an eighth of an inch, we can safely discard any remaining fractional portion.

Thus given our example of 123.45 feet, we can calculate that there are 123 feet, 5 and 3/8 inches.

## Requirements

Use the conversions of 12 inches to every foot and 8 eighth of an inch in every inch. Define these values as `const float` variables.

Perform your calculations using floating point (`double` or `float`) and integer types (`int`) where needed. Use your judgement to know which is the correct type to use.

Do not mix and match `float` type with `double` type. Use only `float` or only `double`.

You shall use [cout](https://en.cppreference.com/w/cpp/io/cout) to print messages to the terminal and you shall use [cin](https://en.cppreference.com/w/cpp/io/cin) to read in values from the keyboard.

The program reads in one floating point value from the terminal, uses as many variables need to convert the floating point value into a feet, inches, and eights of inches. The program prints out a message summarizing the data and the resulting calculation.

The program must work reliably with positive and negative values. The output should be formatted to only display one negative sign should the resulting measurement be a negative value.

The starting code defines a series of `TODO` comments which you can use to formulate your plan and develop your program.

Write your program progressively. Compile your program often and check that you're making progress. Make sure your program behaves the way you expect.

The output of your program must match the output given in the section Example Output below.

To compile your program, you use the `make` command. A Makefile is provided for this exercise.

The Makefile has the following targets:

* all: builds the project
* clean: removes object and dependency files
* spotless: removes everything the clean target removes and all binaries
* format: outputs a [`diff`](https://en.wikipedia.org/wiki/Diff) showing where your formatting differes from the [Google C++ style guide](https://google.github.io/styleguide/cppguide.html)
* lint: output of the [linter](https://en.wikipedia.org/wiki/Lint_(software)) to give you tips on how to improve your code
* header: check to make sure your files have the appropriate header
* test: run tests to help you verify your program is meeting the assignment's requirements. This does not grade your assignment.

## Don't Forget

Please remember that:

- You need to put a header in every file.
- You need to follow the [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html).
- Remove the `TODO` in the comments. For example change `// TODO: Using cin, read the number of feet` to `// Using cin, read the number of feet`. 

## Testing Your Code

Computers only ever do exactly what they are told, exactly the way they are told it, and never anything else. Testing is an important process to writing a program. You need to test for the program to behave correctly and test that the program behaves incorrectly in a predictable way.

As programmers we have to remember that there are a lot of ways that we can write the wrong program and only one to a few ways to write the correct program. We have to be aware of [cognitive biases](https://en.wikipedia.org/wiki/List_of_cognitive_biases) that we may exercise that lead us to believe we have correctly completed our program. That belief may be incorrect and our software may have errors. [Errors in software](https://www.wired.com/2005/11/historys-worst-software-bugs/) may lead to loss of [life](https://www.nytimes.com/2019/03/14/business/boeing-737-software-update.html), [property](https://en.wikipedia.org/wiki/Mariner_1), [reputation](https://en.wikipedia.org/wiki/Pentium_FDIV_bug), or [all of the above](https://en.wikipedia.org/wiki/2009%E2%80%9311_Toyota_vehicle_recalls).

### Test strategy

Start simple, and work your way up. Good tests are specific, cover a broad range of fundamentally different possibilities, can identify issues quickly, easily, and directly, without need for much set up, and can almost be diagnosed by inspection if the code fails to execute the test correctly.

## Example Output

Please ensure your program's output is identical to the example below.

To build your program, use the `make` command. To build the program either type `make` or `make all`. If you make no changes to your source code, `make` will not do anything and say `make: Nothing to be done for 'default'.`

Please make sure the output from your program matches the output from the example given below.

```
$ ls
decimal_feet_to_feet_inch.cc  Makefile	README.md
$ make
set -e; clang++ -MM -g -O3 -Wall -pedantic -pipe -std=c++17 -D LINUX -D AMD64 decimal_feet_to_feet_inch.cc \
| sed 's/\(decimal_feet_to_feet_inch\)\.o[ :]*/\1.o decimal_feet_to_feet_inch.d : /g' > decimal_feet_to_feet_inch.d; \
[ -s decimal_feet_to_feet_inch.d ] || rm -f decimal_feet_to_feet_inch.d
clang++ -g -O3 -Wall -pedantic -pipe -std=c++17 -D LINUX -D AMD64 -c decimal_feet_to_feet_inch.cc
clang++ -g -O3 -Wall -pedantic -pipe -std=c++17 -o decimal_feet_to_feet_inch decimal_feet_to_feet_inch.o 
$ ./decimal_feet_to_feet_inch 
Enter the number of feet you wish to convert to feet-inch: 0
0 feet is 0 feet, 0 inches
$ ./decimal_feet_to_feet_inch 
Enter the number of feet you wish to convert to feet-inch: -7.5
7.5 feet is -7 feet, 6 inches
$ ./decimal_feet_to_feet_inch 
Enter the number of feet you wish to convert to feet-inch: 123.45
123.45 feet is 123 feet, 5 and 3/8 inches
$ ./decimal_feet_to_feet_inch 
Enter the number of feet you wish to convert to feet-inch: 4.3
4.3 feet is 4 feet, 3 and 4/8 inches
$
```

## Test Cases
Test your program before moving on. For each of the test cases below,

1. Look at the test suite, and identify the first test case, its input, and expected output.
1. Run your program with `./date_difference` .
1. Provide the program with the test case input.
1. If the program crashes, use the **debug runtime error** flowchart to debug the error.
1. Observe the program output and decide whether the actual output matches the expected output.
1. If the output **does not match**, declare that the program fails the test. Use the **debug logic error** flowchart to debug the error.
1. Otherwise (the output **does match**), repeat step 2 with the next test case.

If the program works correctly (meaning no runtime or logic errors) for every test case, declare that the program passes the test. You can move on to releasing your code for part 1.


| Test Case | Input      | Expected Output                               |
|-----------|------------|-----------------------------------------------|
| 1         | 12.345     | `12.345 feet is 12 feet, 4 and 1/8 inches`    |
| 2         | 0.125      | `0.125 feet is 0 feet, 1 and 4/8 inches`      |
| 3         | 0.00125    | `0.00125 feet is 0 feet, 0 inches`            |
| 4         | -0.00125   | `-0.00125 feet is -0 feet, 0 inches`          |
| 5         | -13.567    | `-13.567 feet is -13 feet, 6 and 6/8 inches`  |
| 6         | 10         | `10 feet is 10 feet, 0 inches`                |

## Format Check

Use the `make format` command to check your programs formatting. Correctly formatting your source code is a requirement of the grading rubric.

If you make significant changes to your source file, test it again to confirm that it still passes the test suite. Sometimes a small change that looks benign can actually create a bug.

Below is an example of the output of `make format` when you have correctly formatted code.
```
$ make format
2022-09-25 14:20:54,529 - INFO - Checking format for file: decimal_feet_to_feet_inch.cc
2022-09-25 14:20:54,569 - INFO - 😀 Formatting looks pretty good! 🥳
$
```

Below is an example of the output of `make format` when you have source code which has formatting errors. The output is showing you that lines 25 through 32 need to be indented correctly.

```
$ make format
2022-09-25 14:21:32,712 - INFO - Checking format for file: decimal_feet_to_feet_inch.cc
2022-09-25 14:21:32,756 - WARNING - Error: Formatting needs improvement.
2022-09-25 14:21:32,756 - WARNING - Contextual Diff
*** Student Submission (Yours)

--- Correct Format

***************

*** 25,32 ****

  // Main function - the entry point to our program, it does not take command line
  // arguments
  int main(int argc, char const *argv[]) {
! float input_decimal_feet{NAN};
! cout << "Enter the number of feet you wish to convert to feet-inch: ";
    cin >> input_decimal_feet;
--- 25,32 ----

  // Main function - the entry point to our program, it does not take command line
  // arguments
  int main(int argc, char const *argv[]) {
!   float input_decimal_feet{NAN};
!   cout << "Enter the number of feet you wish to convert to feet-inch: ";
    cin >> input_decimal_feet;
2022-09-25 14:21:32,756 - ERROR - 🤯😳😤😫🤬
2022-09-25 14:21:32,757 - ERROR - Your formatting doesn't conform to the Google C++ style.
2022-09-25 14:21:32,757 - ERROR - Use the output from this program to help guide you.
2022-09-25 14:21:32,757 - ERROR - If you get stuck, ask your instructor for help.
2022-09-25 14:21:32,757 - ERROR - Remember, you can find the Google C++ style online at https://google.github.io/styleguide/cppguide.html.
make: *** [Makefile:108: format] Error 1
$ 
```

## Lint Check
Use the `make lint` command to check your program for lint. If you find that your program has lint, then take the necessary steps to correct your program so it is lint free. Lint free source code is a requirement of the grading rubric.

If you make significant changes to your source file, test it again to confirm that it still passes the test suite. Sometimes a small change that looks benign can actually create a bug.

Below is an example of the output of `make lint` when you have correctly formatted code.
```
$ make lint
2022-09-25 14:22:30,017 - INFO - Linting file: decimal_feet_to_feet_inch.cc
2022-09-25 14:22:34,139 - INFO - 😀 Linting passed 🥳
2022-09-25 14:22:34,139 - INFO - This is not an auto-grader.
2022-09-25 14:22:34,140 - INFO - Make sure you followed all the instructions and requirements.
$
```

Below is an example of the output of `make lint` when you have source code with lint. The output is showing you that there are comments with `TODO` and that `TODO` should not be left in a completed program.

```
$ make lint
2022-09-25 14:22:57,771 - INFO - Linting file: decimal_feet_to_feet_inch.cc
2022-09-25 14:23:01,915 - ERROR - Linter found improvements.
2022-09-25 14:23:01,915 - WARNING - /tmp/cpsc-120-solution-lab-04/part-2/decimal_feet_to_feet_inch.cc:13:3: warning: missing username/bug in TODO [google-readability-todo]
  // TODO: Define a constant of type float with the name kInchesInFeet
  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // TODO(mshafae): Define a constant of type float with the name kInchesInFeet
/tmp/cpsc-120-solution-lab-04/part-2/decimal_feet_to_feet_inch.cc:16:3: warning: missing username/bug in TODO [google-readability-todo]
2022-09-25 14:23:01,915 - ERROR - 🤯😳😤😫🤬
2022-09-25 14:23:01,915 - ERROR - Use the output from this program to help guide you.
2022-09-25 14:23:01,915 - ERROR - If you get stuck, ask your instructor for help.
2022-09-25 14:23:01,915 - ERROR - Remember, you can find the Google C++ style online at https://google.github.io/styleguide/cppguide.html.
make: *** [Makefile:111: lint] Error 1
$ 
```

## Push Your Code

After you have certified that your code passes the test suite and format check, release the code by pushing it to GitHub.

As usual, you need to
1. Use a computer that is authenticated to git. If your computer is not already authenticated, use the `gcf.sh` script in the **Git Configuration & Authentication* page in Canvas.
1. Add modified file(s) with the `git add` shell command.
1. Create a git commit with the `git commit -m "<MESSAGE>"` shell command.
1. Send the commit to GitHub.com with the `git push` shell command.
1. Refresh the web view of your repo and confirm that your push went through.

If any of these steps trigger an error message, use the **debug command error** flowchart to resolve the problem.

## Next Steps

After you have pushed your code, you are done with this lab. You may ask your TA for permission to sign out and leave.

