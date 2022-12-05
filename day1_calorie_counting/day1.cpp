#include <iostream>
#include <fstream>
#include <algorithm>

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cout << "usage: ./day1 'calorie list file name'" << std::endl;
		return 1;
	}

	std::ifstream input_file(argv[1]);
	std::string input;
	int calorie_sum = 0;
	int calorie_max = 0;

	while(getline(input_file, input)) {
		if (input != "") {
			calorie_sum += stoi(input);
		}
		else {
			calorie_max = std::max(calorie_sum, calorie_max);
			calorie_sum = 0;
		}
	}

	std::cout << calorie_max << std::endl;

	return 0;

}