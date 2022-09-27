![Grade Estimate](../../actions/workflows/cc-grade_estimate.yml/badge.svg)
![Header](../../actions/workflows/cc-header.yml/badge.svg)

# Instructions

Each sub-directory has an exercise for you to complete. Each exercise subdirectory is prefixed with the string `part-`. The subdirectory contains a README.md which explains the requirements for the exercise.

Start with `part-1` and move through the problems in numerical order. Only move on to the next part when you have completed the current part you are working on.

Every file that you submit must have a header. Please follow the [guidelines provided for this course](https://docs.google.com/document/d/17WkDlxO92zpb26pYM1NIACPcMWtCOlKO7WCrWC6YxRo/edit?usp=sharing).

Please adhere to the [Google C++ coding style](https://google.github.io/styleguide/cppguide.html).

When writing git log comments, please make them descriptive and meaningful. For example, "Fixed my typo that stopped it from compiling." or "Smashed the bug in my main function." are descriptive. Log comments such as "Done" or "upload" are of poor quality.

Each exercise subdirectory has its own [Makefile](https://en.wikipedia.org/wiki/Makefile) which you may use to build and test your progress. Each Makefile has the following targets:

* all: builds the project
* clean: removes object and dependency files
* spotless: removes everything the clean target removes and all binaries
* format: outputs a [`diff`](https://en.wikipedia.org/wiki/Diff) showing where your formatting differes from the [Google C++ style guide](https://google.github.io/styleguide/cppguide.html)
* lint: output of the [linter](https://en.wikipedia.org/wiki/Lint_(software)) to give you tips on how to improve your code
* header: check to make sure your files have the appropriate header
* test: run tests to help you verify your program is meeting the assignment's requirements. This does not grade your assignment.

To build the program use the `make` command. The Makefile's default target is to build `all`. Below is an example of how to use the `make` command.

```
$ ls
Makefile  part-1 part-2   README.md
$ cd part-1
$ make all
set -e; clang++ -MM -g -O3 -Wall -pedantic -pipe -std=c++17 -D LINUX -D AMD64 date_difference.cc \
| sed 's/\(date_difference\)\.o[ :]*/\1.o date_difference.d : /g' > date_difference.d; \
[ -s date_difference.d ] || rm -f date_difference.d
clang++ -g -O3 -Wall -pedantic -pipe -std=c++17 -D LINUX -D AMD64 -c date_difference.cc
clang++ -g -O3 -Wall -pedantic -pipe -std=c++17 -o date_difference date_difference.o 
$ make header
2050-09-01 13:09:53,276 - INFO - Check header for file: date_difference.cc
2050-09-01 13:09:53,278 - INFO - Header found.
2050-09-01 13:09:53,278 - INFO - Name: Tuffy Titan
2050-09-01 13:09:53,278 - INFO - Class: CPSC 120A-01
2050-09-01 13:09:53,278 - INFO - Email: tuffy.titan@csu.fullerton.edu
2050-09-01 13:09:53,278 - INFO - GitHub Handle: ttitan
2050-09-01 13:09:53,279 - INFO - Lab: Lab 04-01
2050-09-01 13:09:53,279 - INFO - Partners:  @peteranteater
2050-09-01 13:09:53,279 - INFO - Comment: Program to calculate the number of days between two Gregorian dates.
$ make format
2050-09-01 13:09:58,498 - INFO - Checking format for file: date_difference.cc
2050-09-01 13:09:58,541 - INFO - 😀 Formatting looks pretty good! 🥳
$ make lint
2050-09-01 13:10:00,417 - INFO - Linting file: date_difference.cc
2050-09-01 13:10:03,339 - INFO - 😀 Linting passed 🥳
2050-09-01 13:10:03,339 - INFO - This is not an auto-grader.
2050-09-01 13:10:03,340 - INFO - Make sure you followed all the instructions and requirements.
$ make test
2050-09-01 13:10:10,269 - INFO - Start Testing Tuffy Titan tuffy.titan@csu.fullerton.edu ttitan
2050-09-01 13:10:10,270 - INFO - All files: ./date_difference.cc
2050-09-01 13:10:10,312 - INFO - ✅ Formatting passed on ./date_difference.cc
2050-09-01 13:10:13,231 - INFO - ✅ Linting passed in ./date_difference.cc
2050-09-01 13:10:19,504 - INFO - ✅ Build passed
2050-09-01 13:10:19,505 - INFO - Test 1 - (1, 1, 2022, 1, 1, 2023, 365)
2050-09-01 13:10:19,914 - INFO - Test 2 - (1, 1, 1984, 1, 1, 1985, 366)
2050-09-01 13:10:20,325 - INFO - Test 3 - (12, 25, 1275, 12, 25, 2522, 455457)
2050-09-01 13:10:20,735 - INFO - Test 4 - (9, 21, 2022, 10, 31, 1980, -15300)
2050-09-01 13:10:21,145 - INFO - Test 5 - (10, 1, 79, 9, 23, 2022, 709658)
2050-09-01 13:10:21,555 - INFO - ✅ All test runs passed
2050-09-01 13:10:21,556 - INFO - End Testing Testing Tuffy Titan tuffy.titan@csu.fullerton.edu ttitan
$ 
```

# Rubric

Each exercise is worth 15 points. There are 2 parts so there is a total of 30 points possible. Each program must compile before it is graded. _Submissions that do not compile shall be assigned a zero grade._

For each problem:

* Functionality (9 points): Your submission shall be assessed for the appropriate constructs and strategies to address the exercise. A program the passes the instructor's tests completely receives full marks. A program that partially passes the instructors tests receives partial-marks. A program that fails the majority or all the tests receives no marks.

* Format & Readability (6 points): Your submission shall be assessed by checking whether your code passess the style and format check, as well as how well it follows the proper naming conventions, and internal documentation guidelines. Git log messages are an integral part of how readable your project is. _Failure to include a header forfeits all marks._

A detailed rubric is assigned to each lab in Canvas.
