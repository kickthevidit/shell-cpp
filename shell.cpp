#include <iostream>
#include <string>
#include <vector>

#include "shell.hpp"

using std::string;
using std::vector;

void shell_run() {
	system("clear");

	string line;
	do {
		std::cout << " > ";
		getline(std::cin, line);

		if (line == "end" || line == "exit") ExitShell();
		vector<vector<string>> args = ParseLine(line);
		ExecuteArgs(args);
	} while (true);
}

int main() {
	shell_run();
}

// clear; clang++ -std=c++20 shell.hpp shell.cpp
// clear; clang++ -std=c++20 shell.hpp shell.cpp; ./a.out