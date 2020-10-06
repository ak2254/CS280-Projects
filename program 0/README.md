CS280 Programming Assignment 0
Spring 2019
Due February 6 before midnight
This assignment is mostly designed to help get you used to the Vocareum system.
Write a C++ program that processes every command line argument, excluding the program
name.
Your program may operate in several modes:
● “Reverse” mode: when enabled, the program reverses the order of the letters in an
argument
● “Upper” mode: when enabled, the program converts all lowercase letters in the argument
to uppercase letters
● “NoVowel” mode: when enabled, the program skips vowels (a, e, i, o, u, A, E, I, O, U)
The program starts with all modes disabled.
As each argument is processed, the program determines the length of each argument. Based
on the length, it may toggle the mode settings (“toggle” means if the mode is disabled, enable it,
and if the mode is enabled, disable it).
Toggling is performed according to the following rules:
1. If the length of the argument is evenly divisible by 2, toggle “Reverse” mode
2. If the length of the argument is evenly divisible by 3, toggle “Upper” mode
3. If the length of the argument is evenly divisible by 5, toggle “NoVowel” mode ok
After determining the length of an argument and processing any mode toggling, the program
must apply any enabled modes to the argument, print the argument out on a line by itself, then
proceed to the next argument.
Note that it is possible, and valid, for there to be no command line arguments after the program
name.
Examples:
$ ./prog0 Hello, nothing world bye world ok
,OLLEH
GNIHTON
DLRW
yb
dlrow
ok
The first argument is of length 6, which toggles both Reverse and Upper to on
The second argument is of length 7, nothing changes
The third argument is of length 5, which toggles NoVowel to on
The fourth argument is of length 3, which toggles Upper off
The fifth argument is of length 5, which toggles NoVowel to off
The sixth argument is of length 2, which toggles Reverse to off
$ ./prog0 several nothing wording changes
several
nothing
wording
changes
$ ./prog0 who put the bomp in the bomp she bomp she bomp?
WHO
put
THE
PMOB
IN
the
pmob
EHS
BOMP
she
bmp?