#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>

#include "generators.h"
#include "file_readers.h"
#include "algorithms.h"
#include "file_getter.h"
using namespace std;

void run(istream& in, ostream& out, int& countAssign, int& countCompare)
{
	while (in.good())	// get every data piece
	{
		// reset count results
		countAssign = 0;
		countCompare = 0;

		// get one piece of data
		// CHANGE HERE TO YOUR READER
		vector<int> arr = readIntArray(in);

		// run algorithm once on a piece of data
		// CHANGE HERE TO YOUR ALGORITHM
		insertion_sort(arr, countAssign, countCompare);

		// save count results
		out << countAssign << "," << countCompare << endl;
	}
}

int main(int argc, char* argv[])
{
	if (argc != 6)
	{
		cout << "Usage: Ex03_src.exe <number_of_data> <data_size> <data_file> <output_file> <case>" << endl;
		cout << "Example: run.exe 1000 1000 data.txt result.txt best" << endl;
		cout << "<case> is best, worst, average" << endl;
		return 0;
	}

	// get data sizes
	int n, m;
	m = atoi(argv[1]);
	n = atoi(argv[2]);

	// generate data
	// CHANGE HERE TO YOUR DATA GENERATOR
	// COMMENT IF YOU ALREADY HAVE DATA
	// depend on best case, worst case or average case
	if (strcmp(argv[5], "best") == 0) {
		genOrderedIntArray(m, n, argv[3], true);
	}
	else if (strcmp(argv[5], "worst") == 0) {
		genOrderedIntArray(m, n, argv[3], false);
	}
	else if (strcmp(argv[5], "average") == 0) {
		genRandomIntArray(m, n, argv[3]);
	}
	else {
		cout << "Usage: Ex03_src.exe <number_of_data> <data_size> <data_file> <output_file> <case>" << endl;
		cout << "Example: run.exe 1000 1000 data.txt result.txt best" << endl;
		cout << "<case> is best, worst, average" << endl;
		return 0;
	}

	ifstream inFile(argv[3]);
	ofstream outFile(argv[4]);
	// open files
	if (!inFile.is_open() || !outFile.is_open())
	{
		cout << "run: Error opening files" << endl;
		return 1;
	}

	int countAssign, countCompare;
	// run algorithm and count
	run(inFile, outFile, countAssign, countCompare);

	// close files
	inFile.close();
	outFile.close();

	return 0;
}