DEPENDENCIES:
	
	Requires C++11, OpenSSL, OpenSSL cryptography and POSIX threads libraries
	Please add the correct path to these libraries in the Makefile
	PLEASE BE EXTREMELY CAREFUL WHEN USING make clean


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
