//Advent of Code Day 4 Part 2
//Caden Unnasch
//12/14/22

#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
#include <getopt.h>

int main(int argc, char* argv[]) {
	//argument processing
	bool verbose = false;
	int opt;
	std::string file_arg = "";

	while ((opt = getopt(argc, argv, "-v")) != -1) {
		switch (opt) {
		case 'v':
		   verbose = true;
		   break;
		case 1:
			file_arg = optarg;
			break;
		default: /* '?' */
		   fprintf(stderr, "Usage: %s [-v] input_file_path\n",
		           argv[0]);
		   exit(-1);
		}
    }

    if (file_arg == "") {fprintf(stderr, "Usage: %s [-v] input_file_path\n", argv[0]); exit(-1);}

	std::ifstream input_file(file_arg);
	std::string input_line;

	int pair_counter = 1;

	int overlap_counter = 0;

	while(getline(input_file, input_line)) {
		std::string first_range = input_line.substr(0, input_line.find(','));
		std::string second_range = input_line.substr(input_line.find(',') + 1);

		int range1low = stoi(first_range.substr(0, first_range.find('-')));
		int range1high = stoi(first_range.substr(first_range.find('-') + 1));
		int range2low = stoi(second_range.substr(0, second_range.find('-')));
		int range2high = stoi(second_range.substr(second_range.find('-') + 1));
		

		if (verbose) {
			std::cout << "Pair number " << pair_counter++ << std::endl;
			std::cout << "First range: " << first_range << std::endl;
			std::cout << "Second range: " << second_range << std::endl;

			std::cout << range1low << ' ' << range1high << std::endl;
			std::cout << range2low << ' ' << range2high << std::endl;
		}

		if ((range1low >= range2low && range1low <= range2high) || (range2low >= range1low && range2low <= range1high)) {
			overlap_counter++;
			if (verbose) {
				std::cout << "Overlap counter incremented!" << std::endl;
			}
		}
		else if (verbose) {
			std::cout << "Overlap counter not incremented!" << std::endl;
		}

		if (verbose) std::cout << std::endl;
	}

	std::cout << "There were "<< overlap_counter << 
		" pairs where one range overlapped with the other." << std::endl;

	return 0;
}