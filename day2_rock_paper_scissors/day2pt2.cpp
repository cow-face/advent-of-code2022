#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char* argv[]) {
	//argument processing
	if (argc != 2) {
		std::cout << "usage: ./day2 'rock paper scissors file name'" << std::endl;
		return 1;
	}

	std::ifstream input_file(argv[1]);
	std::string input_line;

	int score = 0;

	while(getline(input_file, input_line)) {
		std::stringstream input_stream(input_line);
		char opponent_char;
		char your_char;
		input_stream >> opponent_char;
		input_stream >> your_char;

		int opponent_move = opponent_char - 64;
		int your_move;
		int outcome = your_char - 87;
		std::cout << opponent_move;
		std::cout << outcome << std::endl;

		switch (outcome) {
		case 1:
			switch(opponent_move) {
			case 1:
				your_move = 3;
				break;
			case 2:
				your_move = 1;
				break;
			case 3:
				your_move = 2;
				break;
			};
			break;
		case 2:
			your_move = opponent_move;
			score += 3;
			break;
		case 3:
			switch (opponent_move) {
			case 1:
				your_move = 2;
				break;
			case 2:
				your_move = 3;
				break;
			case 3:
				your_move = 1;
				break;
			}
			score += 6;
			break;
		};
		score += your_move;

	}

	std::cout << score << std::endl;
}