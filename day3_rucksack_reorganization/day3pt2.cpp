//Advent of Code Day 3 Part 2
//Caden Unnasch
//12/14/22

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

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
	std::vector<std::string> elves(3);

	int priority_sum = 0;
	int group_counter = 1;
	
	while (std::getline(input_file, elves[0])) {
		std::cout << "Group number " << group_counter++ << std::endl;

		std::getline(input_file, elves[1]);
		std::getline(input_file, elves[2]);

		std::cout << "First elf:  " << elves[0] << std::endl;
		std::cout << "Second elf: " << elves[1] << std::endl;
		std::cout << "Third elf: "  << elves[2] << std::endl;

		for (char elem : elves[0]) {
			if (elves[1].find(elem) != std::string::npos && 
				elves[2].find(elem) != std::string::npos) {

				int priority = char_to_priority(elem);
				std::cout << elem << " appears in all rucksacks which has a priority of " << priority << std::endl;
				priority_sum += priority;
				break;
			}
		}
		std::cout << std::endl;
	}

	std::cout << priority_sum << std::endl;

	return 0;
}