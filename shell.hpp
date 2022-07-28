#ifndef SHELL_
#define SHELL_

#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <map>

using std::string;
using std::vector;
using std::map;

#include "commands.hpp"

void ExitShell(const string& command = string()) {
	std::cout << "Command not found: " << command;
	exit(EXIT_SUCCESS);
}

vector<vector<string>> ParseLine(string &line) {
	/*
		split using whitespaces, quotes, backslash and semicolon
		if whitespace, arg over
		if quote, arg until endquote
		if backslash, ignore end-line or whitespace
		if semicolon, then the next command not to be confused with this command
	*/
	vector<vector<string>> args;

	string arg;

	int vec_count = 0;
	args.push_back(vector<string>());
	bool quote_mode = false;
	for (int i = 0; i < line.size(); ++i) {
		switch (line[i]) {
			case ' ': // new arg
				if (!quote_mode) {
					if (!arg.empty()) args[vec_count].push_back(arg);
					arg = "";
				} else arg += line[i];
				break;
			case ';': // new command
				if (!quote_mode) {
					if (!arg.empty()) args[vec_count].push_back(arg);
					arg = "";
					args.push_back(vector<string>());
					++vec_count;
                } else arg += line[i];
				break;
			case '\\': // ignore next whitespace or next newline
				if (!quote_mode && std::isspace(line[i+1])) {
					arg+=line[i+1];
					++i;
				}
				break;
			case '"':
				quote_mode = !quote_mode;
				break;
			default:
				arg+=line[i];
				break;
		}
	}
	args[vec_count].push_back(arg);

	return args;
}

// void ExecuteArgs(const vector<vector<string>>& args) {
// 	if (args.empty() || args[0].empty()) throw std::runtime_error("ExecuteArgs-> args is invalid");

// 	std::cout << args.size() << '\n';
// 	std::cout << "Executing Args: ";
// 	for (const vector<string>& v: args) {
// 		std::cout << v.size() << ':';
// 		for (const string& a: v) {
// 			std::cout << a << ',';
// 		}
// 		std::cout << '\n';
// 	}

// 	for (const vector<string>& command: args) {
// 		if (args.at(0).empty()) throw std::runtime_error("ExecuteArgs-> initial string is empty");

// 		if (Command::func.find(command.at(0)) == Command::func.end()) ExitShell(command.at(0));
// 		Command::func.find(command.at(0))(command);
// 	}
// }



#endif