#ifndef COMMANDS_
#define COMMANDS_

#include <iostream>
#include <string>
#include <map>
#include <functional>
#include <vector>
#include <filesystem>

using std::string;
using std::map;
using std::vector;

void ExitShell(const string &command = string(), bool verbose = 0) {
  if (verbose)
    std::cout << "Command not found: " << command;
  exit(EXIT_SUCCESS);
}

void ThrowError(const string& command) {
  std::cout << "Command not found: " << command << '\n';
}

namespace Command {

void echo(const vector<string> &words) {
  if (words.size() == 1) return;
  for (int i = 1; i < words.size(); ++i) {
    std::cout << words[i] << ' ';
  }
  std::cout << '\n';
}

void help(const vector<string>& words) {
	std::cout << "You can use one of the following commands: \n";
	std::cout << "help, echo";
	std::cout << "\n";
}

void clear(const vector<string>& words) {
  system("clear");
}

void pwd(const vector<string>& words) {
  system("pwd");
}

void exit(const vector<string> &words) {
  ExitShell(string());
}

// TODO: make cd work;
void cd(const vector<string>& words) {
  string params = words.at(0);
  for (int i = 1; i < words.size(); ++i) {
    params+= ' ' + words.at(i);
  }
  // std::cout << params << '\n';
  system(params.c_str());
  system("cd");
  Command::pwd(words);
}

void ls(const vector<string> &words) {
  string params = words.at(0);
  for (int i = 1; i < words.size(); ++i) {
    params += ' ' + words.at(i);
  }
  system(params.c_str());
}
}

#endif