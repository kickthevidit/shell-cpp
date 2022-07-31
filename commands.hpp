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

void ExitShell(const string &command = string(), bool verbose = 0, const string& error_message = string()) {
  if (verbose)
    std::cout << "Error at Command: " << command << ((error_message == string()) ? "" : error_message);
  exit(EXIT_SUCCESS);
}

void ThrowError(const string& command = string()) {
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

void exit(const vector<string> &words) {
  ExitShell(string());
}

// TODO: make cd work;
void cd(const vector<string>& words) {
  string params = "";// = words.at(0);
  for (int i = 1; i < words.size(); ++i) {
    params+= words.at(i);
    if (i != 1) params += ' ';
  }

  std::filesystem::path a(params);
  try {
    if (std::filesystem::exists(a)) {
      std::filesystem::current_path(a);
      system("pwd");
    }
  } catch (std::filesystem::filesystem_error) {
    std::cout << "Error: " << params << " is not a directory\n";
  }
}

void unix_func(const vector<string>& words) {
  /* executes all the functions here" https://man7.org/linux/man-pages/dir_section_2.html */
  string params = words.at(0);
  for (int i = 1; i < words.size(); ++i) {
    params += ' ' + words.at(i);
  }
  system(params.c_str());
}
}

#endif