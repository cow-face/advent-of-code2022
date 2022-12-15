//Advent of Code Day 5 Part 1
//Caden Unnasch
//12/14/22

#include <iostream>
#include <string>
#include <fstream>
#include <deque>
#include <sstream>
#include <algorithm>
#include <unistd.h>
#include <getopt.h>

const char* USAGE = "Usage: %s [-v] [-r rows] [-c cols] input_file_path\n";

void print_crate_stack(std::deque<std::deque<char>> crate_stack, int cols) {
	int max_rows = 0;
	for (int col = 0; col < cols; col++) {
		max_rows = std::max(max_rows, static_cast<int>(crate_stack[col].size()));
	}

	for (int row = 0; row < max_rows; row++) {
    		for (int col = 0; col < cols; col++) {
    			if (row > crate_stack[col].size() - 1) {
    				std::cout << "  ";
    			}
    			else {
    				std::cout << crate_stack[col][row] << " ";
    			}
    	}
    	std::cout << std::endl;
    }
    std::cout << std::endl;

    for (int col = 0; col < cols; col++) {
    	std::cout << col + 1 << ' ';
    }
    std::cout << std::endl;
}

int main(int argc, char* argv[]) {
	//argument processing
	int opt;

	bool verbose = false;
	std::string file_arg = "";
	int rows = 8;
	int cols = 9;

	while ((opt = getopt(argc, argv, "-vr:c:")) != -1) {
		switch (opt) {
		case 'v':
		   verbose = true;
		   break;
		case 1:
			file_arg = optarg;
			break;
		case 'r':
			rows = std::stoi(optarg);
			break;
		case 'c':
			cols = std::stoi(optarg);
			break;
		default: /* '?' */
		   fprintf(stderr, USAGE,
		           argv[0]);
		   exit(-1);
		}
    }

    if (file_arg == "") {fprintf(stderr, USAGE, argv[0]); exit(-1);}

    std::ifstream input_file(file_arg);
    std::string crate_row;

    std::deque<std::deque<char>> columns(cols);

    for (int row = 0; row < rows; row++) {
    	getline(input_file, crate_row);
    	for (int col = 0; col < cols; col++) {
    		if (crate_row[col*4 + 1] != ' ') {
    			columns[col].push_back(crate_row[col*4 + 1]);
    		}
    	}
    }

    if (verbose) {
    	print_crate_stack(columns, cols);
    }

    while(getline(input_file, crate_row)) {
    	if (crate_row.find("move") != std::string::npos) {
    		std::stringstream crate_move_stream(crate_row);

    		std::string garbage;
    		int num_crates, from_col, to_col;
    		crate_move_stream >> garbage >> num_crates >> garbage;
    		crate_move_stream >> from_col >> garbage >> to_col;

    		if (verbose) {
    			std::cout << "Num crates: " << num_crates << std::endl;
    			std::cout << "From col: " << from_col << std::endl;
    			std::cout << "To col: " << to_col << std::endl;

    			std::cout << std::endl;
    		}

    		from_col--;
    		to_col--;

    		for (int i = 0; i < num_crates; i++) {
    			char crate = columns[from_col][0];
    			columns[from_col].pop_front();

    			columns[to_col].push_front(crate);
    		}

    		if (verbose) {
    			print_crate_stack(columns, cols);
    			std::cout << std::endl;
    		}
    	}
    }

    if (verbose) {
    	print_crate_stack(columns, cols);
    }

    for (int col = 0; col < cols; col++) {
    	std::cout << columns[col][0];
    }

    std::cout << std::endl;

    return 0;
}