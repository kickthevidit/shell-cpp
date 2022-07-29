/*
TODOS:
	- Add mkdir functionality
	- Fix cd function
	
*/

#include <iostream>
#include <regex>
#include <string>
#include <vector>

#include "shell.hpp"

using std::string;
using std::vector;

void shell_run() {
	system("clear");
	
	bool status = true;
	string line;

	do {
		std::cout << "> ";
		getline(std::cin, line);

		if (line == "end") ExitShell();

		vector<vector<string>> args = ParseLine(line);

		ExecuteArgs(args);

	} while (status);
}

int main() {
	shell_run();
}

// clear; clang++ -std=c++20 shell.hpp shell.cpp
// clear; clang++ -std=c++20 shell.hpp shell.cpp; ./a.out