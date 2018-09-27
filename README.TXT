This is my final project for Operating Systems spring 2018.
The program models total drive seek distance when using FIFO head scheduling. 
I compare multiple 'on disk' Cache locations to evaluate what offers best performance. The caches are stored in an "organ" fashion such that if you graph block frequency it will have the highest frequency in the middle decreasing as you go furthur out.


/scripts
	contains a variety of scripts for extracting and finding key values from a trace
	also contains test.sh which will compile and calculate results
	IMPORTANT test.sh must be edited to include the complete path to the project folder

/headers
	contains header files


/implementation
	contains implementation of header files


/data
	dumping ground for pre-processed data, it also contains a written report

/results
	contains results after test.sh is run as well as the report

Compiling:
	use provided makefile
	must compile with c++11

