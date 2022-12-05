#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

int main(int argc, char* argv[]) {
	//argument processing
	if (argc != 2) {
		std::cout << "usage: ./day1 'calorie list file name'" << std::endl;
		return 1;
	}

	//file input
	std::ifstream input_file(argv[1]);
	std::string input;

	int calorie_sum = 0;
	int calorie_max = 0;
	std::vector<int> calorie_sums;

	//getting sums
	while(getline(input_file, input)) {
		if (input != "") {
			calorie_sum += stoi(input);
		}
		else {
			calorie_sums.push_back(calorie_sum);
			calorie_sum = 0;
		}
	}

	//sorting sums in descending order
	std::sort(calorie_sums.begin(), calorie_sums.end(), std::greater<int>());

	//getting top 3 sums
	int top_elves_sum = 0;
	for (int i = 0; i < 3; i++) {
		std::cout << calorie_sums[i] << std::endl;
		top_elves_sum += calorie_sums[i];
	}

	std::cout << top_elves_sum << std::endl;

	return 0;

}