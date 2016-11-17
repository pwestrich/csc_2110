Assignment #3
“Line Simulator” 
by Philip Westrich
for CSC 2110-002
Wednesday, April 3, 2013

Description
—————————————
This program simulates a multi-server, single queue system, such as waiting in line for a teller at the bank.

Usage
—————————————
The program will prompt you for the following values:

	Simulation length (between 0 and 36000)
	Average transaction time (between 2 and 600)
	Number of servers (between 0 and 10)
	Average time between arrivals (between 1 and 100)

It will not accept values outside the limits.

Once the program is given valid input, it will calculate then print the results:

	Number of people served
	Average wait time (to 2 decimal places)
	Number still waiting in line 

If you wish to run multiple simulations, run the program multiple times.

Compiling
—————————————
To compile the program, first navigate to the proper directory and enter the following command:

	g++ -o Simulator main.cpp

Be sure all of the files are in the directory and your compiler is set up properly.

Also, the program’s input limits can be adjusted; they are in the main.h file.

This program was written, tested and compiled with Xcode in Mac OS 10.8.3.