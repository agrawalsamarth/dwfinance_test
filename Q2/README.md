DEPENDENCIES:
	
	Requires C++11, OpenSSL, OpenSSL cryptography and POSIX threads libraries
	Please add the correct path to these libraries in the Makefile
	PLEASE BE EXTREMELY CAREFUL WHEN USING make clean

MAKEFILE UPDATES:

	In case you need to add the path to OpenSSL include folder Line 4 and 5 must be changed. And Lines 6,7,8 must be changed in order to add the libraries openssl, openssl cryptography and posix threads

INSTALLATION:

	make all

USAGE:

	./bin/main
	
OUTPUT FORMAT:

	The program outputs stream of trades from fapi.binance.com and is parsed in the format, as asked for in the test. The last 3 lines provides the total time for retrieving the data and parsing.
	
CODE STRUCTURE:

	In order to optimize for speed, we hard code the parameters, and look for structure in the incoming stream of text, while sacrificing for speed.
	It uses two classes:

		#Connector: Uses openssl to establish get request and retrieve data
		#ParserForBinance: Custom parser for the incoming stream of data

	For 500 trades, the parsing routines takes rought 10 milliseconds on a Intel(R) Core(TM) i7-10750H CPU @ 2.60GHz machine
