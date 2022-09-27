
# Date Difference

How many days until your next birthday? How many days since you adopted your dog/cat/fish? Wouldn't it be great if we could quickly calculate the number of days between any two given dates!

How can this be done? If we could take a given date, say December 5, 1933, and convert it to the number of days since the epoch (beginning of time) then we could easily do date differences and sums. How do we select a specific date as our epoch? How do we account for leap years? (When exactly is the beginning of time?)

In the United States, we use a [Gregorian Calendar](https://en.wikipedia.org/wiki/Gregorian_calendar). It was introduced in 1582 and it replaced the [Julian Calendar](https://en.wikipedia.org/wiki/Julian_calendar). Our program is going to expect a date expressed as a date on a Gregorian calendar, such as January 1, 1970 [CE](https://en.wikipedia.org/wiki/Common_Era).

Thanks to [Fliegel & Van Flandern](https://dl.acm.org/doi/pdf/10.1145/364096.364097), there is a very compact formula to take a given date in the Gregorian calendar and convert it to an integer that represents the number of days since day zero. This is called a Julian Day. In their algorithm, day zero is November 24, 4713 [BCE](https://en.wikipedia.org/wiki/Common_Era)! This means that we can very easily calculate date differences from November 24, 4713 BCE to some where past the year 5,000,000 with `int` types.

With this information in hand, we can convert a given date to a Julian Day and then take the difference between the two Julian Days to know the number of days between them.

Fliegel & Van Flandern's algorithm is [restated on the Julian Day Wikipedia page](https://en.wikipedia.org/wiki/Julian_day#Julian_day_number_calculation) with some slight modifications. Below is a modestly modified line of code from the [US Naval Obervatory's NOVAS](https://github.com/indigo-astronomy/novas) source code which calculates a Julian Day (`int`) from a Gregorian Date, for example 1/23/2021 where 1 is the month January, 23 is the 23rd day of the month and 2021 is the year.

```C++
int month = 1;
int day = 23;
int year = 2021;
int julian_day = day - 32075 + 1461
      * (year + 4800 + (month - 14) / 12) / 4
      + 367 * (month - 2 - (month - 14) / 12 * 12) / 12 - 3
      * ((year + 4900 + (month - 14) / 12) / 100) / 4;
```

This is a long formula with many expressions. Before you start blaming the computer for _doing things wrong_, double check your work. Make sure you have all the operations and parentheses in the right places. A small typo can make a big difference in the result.

To help you test your work, we know that January 1, 2021 is the Julian day 2,459,216 and January 1, 1990 is the Julian day 2,447,893. The number of days between these two dates is 11,323. Additional examples are in the section _Example Input and Output_.

You can also test your work by checking how many days there are in a [year](https://en.wikipedia.org/wiki/Calendar_year). (Recall that there are 365 days in a typical year.) This means that between January 1, 2021 and January 1, 2022, there are 365 days. However, between January 1, 2020 and January 1, 2021 there are 366 days because the year 2020 is a [leap year](https://en.wikipedia.org/wiki/Leap_year.)

## Requirements

Use the Fliegel & Van Flandern's algorithm to convert two dates into Julian Days and then take the difference. Only `int` types can be used to perform the calculations. Do not use `float` or `double`.

You shall use [cout](https://en.cppreference.com/w/cpp/io/cout) to print messages to the terminal and you shall use [cin](https://en.cppreference.com/w/cpp/io/cin) to read in values from the keyboard.

The program reads in six values from the terminal, stores them in at least six different variables and then prints out a message summarizing the data and the resulting calculation.

The starting code defines a series of `TODO` comments which you can use to formulate your plan and develop your program.

Write your program progressively. Compile your program often and check that you're making progress. Make sure your program behaves the way you expect.

The output of your program must match the output given in the section _Example Input and Output_ below.

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
- Remove the `TODO` in the comments. For example change `// TODO: Using cin, read the start month value from the terminal` to `// Using cin, read the start month value from the terminal`. 

## Testing Your Code

Computers only ever do exactly what they are told, exactly the way they are told it, and never anything else. Testing is an important process to writing a program. You need to test for the program to behave correctly and test that the program behaves incorrectly in a predictable way.

As programmers we have to remember that there are a lot of ways that we can write the wrong program and only one to a few ways to write the correct program. We have to be aware of [cognitive biases](https://en.wikipedia.org/wiki/List_of_cognitive_biases) that we may exercise that lead us to believe we have correctly completed our program. That belief may be incorrect and our software may have errors. [Errors in software](https://www.wired.com/2005/11/historys-worst-software-bugs/) may lead to loss of [life](https://www.nytimes.com/2019/03/14/business/boeing-737-software-update.html), [property](https://en.wikipedia.org/wiki/Mariner_1), [reputation](https://en.wikipedia.org/wiki/Pentium_FDIV_bug), or [all of the above](https://en.wikipedia.org/wiki/2009%E2%80%9311_Toyota_vehicle_recalls).

### Test strategy

Start simple, and work your way up. Good tests are specific, cover a broad range of fundamentally different possibilities, can identify issues quickly, easily, and directly, without need for much set up, and can almost be diagnosed by inspection if the code fails to execute the test correctly.

As stated earlier, to help you test your work, we know that January 1, 2021 is the Julian day 2,459,216 and January 1, 1990 is the Julian day 2,447,893. The number of days between these two dates is 11,323.

You can also test your work by checking how many days there are in a [year](https://en.wikipedia.org/wiki/Calendar_year). (Recall that there are 365 days in a typical year.) This means that between January 1, 2021 and January 1, 2022, there are 365 days. However, between January 1, 2020 and January 1, 2021 there are 366 days because the year 2020 is a [leap year](https://en.wikipedia.org/wiki/Leap_year.)

## Example Input and Output

Please ensure your program's output is identical to the example below.

To build your program, use the `make` command. To build the program either type `make` or `make all`. If you make no changes to your source code, `make` will not do anything and say `make: Nothing to be done for 'default'.`

Please make sure the output from your program matches the output from the example given below.

```
$ ls
date_difference.cc  Makefile  README.md
$ make all
set -e; clang++ -MM -g -O3 -Wall -pedantic -pipe -std=c++17 -D LINUX -D AMD64 date_difference.cc \
| sed 's/\(date_difference\)\.o[ :]*/\1.o date_difference.d : /g' > date_difference.d; \
[ -s date_difference.d ] || rm -f date_difference.d
clang++ -g -O3 -Wall -pedantic -pipe -std=c++17 -D LINUX -D AMD64 -c date_difference.cc
clang++ -g -O3 -Wall -pedantic -pipe -std=c++17 -o date_difference date_difference.o 
$ ./date_difference
Let's find the number of days between two dates...
Enter a start month: 1
Enter a start day: 1
Enter a start year: 2020

Enter an end month: 1
Enter an end day: 1
Enter an end year: 2021

The number of days between 1/1/2020 and 1/1/2021 is 366 days
$ ./date_difference
Let's find the number of days between two dates...
Enter a start month: 1
Enter a start day: 1
Enter a start year: 1990

Enter an end month: 1
Enter an end day: 1
Enter an end year: 2021

The number of days between 1/1/1990 and 1/1/2021 is 11323 days
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

| Test Case | Input                              | Expected Output                                                       |
|-----------|------------------------------------|-----------------------------------------------------------------------|
| 1         | 1, 1, 2022, 1, 1, 2023             | `The number of days between 1/1/2022 and 1/1/2023 is 365 days`        |
| 2         | 1, 1, 1984, 1, 1, 1985             | `The number of days between 1/1/1984 and 1/1/1985 is 366 days`        |
| 3         | 12, 25, 1275, 12, 25, 2522         | `The number of days between 12/25/1275 and 12/25/2522 is 455457 days` |
| 4         | 9, 21, 2022, 10, 31, 1980          | `The number of days between 9/21/2022 and 10/31/1980 is -15300 days`  |
| 5         | 10, 1, 79, 9, 23, 2022             | `The number of days between 10/1/79 and 9/23/2022 is 709658 days`     |

## Format Check

Use the `make format` command to check your programs formatting. Correctly formatting your source code is a requirement of the grading rubric.

If you make significant changes to your source file, test it again to confirm that it still passes the test suite. Sometimes a small change that looks benign can actually create a bug.

Below is an example of the output of `make format` when you have correctly formatted code.
```
$ make format
2022-09-25 13:43:17,945 - INFO - Checking format for file: date_difference.cc
2022-09-25 13:43:17,988 - INFO - 😀 Formatting looks pretty good! 🥳
$
```

Below is an example of the output of `make format` when you have source code which has formatting errors. The output is showing you that lines 42 through 50 need to be indented correctly.

```
$ make format
2022-09-25 13:44:55,463 - INFO - Checking format for file: date_difference.cc
2022-09-25 13:44:55,505 - WARNING - Error: Formatting needs improvement.
2022-09-25 13:44:55,505 - WARNING - Contextual Diff
*** Student Submission (Yours)

--- Correct Format

***************

*** 42,50 ****

  /// Main function - the entry point to our program, it does not take command
  /// line arguments
  int main(int argc, char const *argv[]) {
! cout << "Let's find the number of days between two dates...\n";
! cout << "Enter a start month: ";
! int start_month{0};
    cin >> start_month;
    cout << "Enter a start day: ";
    int start_day{0};
--- 42,50 ----

  /// Main function - the entry point to our program, it does not take command
  /// line arguments
  int main(int argc, char const *argv[]) {
!   cout << "Let's find the number of days between two dates...\n";
!   cout << "Enter a start month: ";
!   int start_month{0};
    cin >> start_month;
    cout << "Enter a start day: ";
    int start_day{0};
2022-09-25 13:44:55,505 - ERROR - 🤯😳😤😫🤬
2022-09-25 13:44:55,505 - ERROR - Your formatting doesn't conform to the Google C++ style.
2022-09-25 13:44:55,505 - ERROR - Use the output from this program to help guide you.
2022-09-25 13:44:55,505 - ERROR - If you get stuck, ask your instructor for help.
2022-09-25 13:44:55,505 - ERROR - Remember, you can find the Google C++ style online at https://google.github.io/styleguide/cppguide.html.
make: *** [Makefile:108: format] Error 1
$ 
```

## Lint Check
Use the `make lint` command to check your program for lint. If you find that your program has lint, then take the necessary steps to correct your program so it is lint free. Lint free source code is a requirement of the grading rubric.

If you make significant changes to your source file, test it again to confirm that it still passes the test suite. Sometimes a small change that looks benign can actually create a bug.

Below is an example of the output of `make lint` when you have correctly formatted code.
```
$ make lint
2022-09-25 13:46:44,519 - INFO - Linting file: date_difference.cc
2022-09-25 13:46:47,446 - INFO - 😀 Linting passed 🥳
2022-09-25 13:46:47,446 - INFO - This is not an auto-grader.
2022-09-25 13:46:47,446 - INFO - Make sure you followed all the instructions and requirements.
$ 
```

Below is an example of the output of `make lint` when you have source code with lint. The output is showing you that there are comments with `TODO` and that `TODO` should not be left in a completed program.

```
$ make lint
2022-09-25 13:48:26,624 - INFO - Linting file: date_difference.cc
2022-09-25 13:48:29,472 - ERROR - Linter found improvements.
2022-09-25 13:48:29,472 - WARNING - /tmp/cpsc-120-solution-lab-04/part-1/date_difference.cc:11:3: warning: missing username/bug in TODO [google-readability-todo]
  // TODO: Using cout, prompt the user for a starting month
  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // TODO(ttitan): Using cout, prompt the user for a starting month
/tmp/cpsc-120-solution-lab-04/part-1/date_difference.cc:13:3: warning: missing username/bug in TODO [google-readability-todo]
2022-09-25 13:48:29,473 - ERROR - 🤯😳😤😫🤬
2022-09-25 13:48:29,473 - ERROR - Use the output from this program to help guide you.
2022-09-25 13:48:29,473 - ERROR - If you get stuck, ask your instructor for help.
2022-09-25 13:48:29,473 - ERROR - Remember, you can find the Google C++ style online at https://google.github.io/styleguide/cppguide.html.
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

After you have pushed your code, move on to part 2.

