#include <iostream>
//Advent of Code Day 3 Part 1
//Caden Unnasch
//12/14/22

#include <string>
#include <fstream>
#include <sstream>

int char_to_priority(char input) {
	if (input >= 97 && input <= 122) {
		return input - 96;
	}
	return input - 38;
}

int main(int argc, char* argv[]) {
	//argument processing
	if (argc != 2) {fprintf(stderr, "USAGE: %s input_file_name\n", argv[0]); exit(-1);}

	std::ifstream input_file(argv[1]);
	std::string input_line;

	int priority_sum = 0;
	int rucksack_counter = 1;
	
	while (std::getline(input_file, input_line)) {
		std::cout << "Rucksack number " << rucksack_counter++ << std::endl;

		int length = input_line.length();

		std::string first_compartment  = input_line.substr(0, length/2);
		std::string second_compartment = input_line.substr(length/2);

		std::cout << "First compartment:  " << first_compartment << std::endl;
		std::cout << "Second compartment: " << second_compartment << std::endl;

		for (char elem : first_compartment) {
			if (second_compartment.find(elem) != std::string::npos) {
				int priority = char_to_priority(elem);
				std::cout << elem << " appears in both rucksacks which has a priority of " << priority << std::endl;
				priority_sum += priority;
				break;
			}
		}
		std::cout << std::endl;
	}

	std::cout << priority_sum << std::endl;

	return 0;
}