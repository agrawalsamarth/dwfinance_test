DEPENDENCIES:
	
	Requires C++11 and libcurl library
	Please edit the Makefile to include the address the of the curl library
	PLEASE BE EXTEREMLY CAREFUL WHEN USING make clean

CHANGES TO MAKEFILE:

	Please change Line 4 and Line 5 of the Makefile in case you need to add the path to the include folder of the curl library, and line 6 for the path to the curl library 

INSTALLATION:

	make all


USAGE:
	./bin/main for the main program
	./bin/example for a tailor-made test case
	
OUTPUT FORMAT:

	The main file executes the problem statement provided in the test.pdf and allows the user to choose the function to be implemented on the data scraped from the link provided. The example case processes a test case where the answer is already known.
	
CODE STRUCTURE:

	The code is built around the Complete Database class which executes the functions asked for in the test. It contains the following classes:
	
		# WebCrawler -- Uses the curl library, and scrapes data from the website to return to a string
		# WordProcesser -- Given a block of text it returns all words. It uses the legitChar structure
		# CustomHashMap -- A custom built hash map, which stores the value of a word and its latest position in the text
