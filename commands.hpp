#ifndef COMMANDS_
#define COMMANDS_

namespace Command {
const map<const string, std::function<void()>> func = {
    {"echo", &echo(const vector<string>& words)}, {"help", &help(const vector<string>& words)}};

void echo(const vector<string> &words) {
  for (const string &w : words)
    std::cout << w << ' ';
}

void help(const vector<string>& words) {
	std::cout << "You can use one of the following commands: \n";
	std::cout << "help, echo";
}
}

#endif