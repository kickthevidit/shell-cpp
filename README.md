# C++ shell

Writing a linux shell in C++. Full unix functionality has been added to this shell, meaning it can run all unix commands [here](https://man7.org/linux/man-pages/dir_section_2.html). It has integration with quotes, backslashes and semicolons for writing better commands. In the future, I want to add autofill functionality as well.

In order to run clone and run using your favorite c++ compiler. Here is how you run the program if you have installed Clang.

```
git clone https://github.com/kickthevidit/shell-cpp
cd shell-cpp
clang++ -std=c++20 commands.hpp shell.hpp shell.cpp;./a.out # if you have Gcc installed just swap the clang++ with gcc
```

Then run whatever linux commands you feel like running. For example, you can run these:
```
clear; curl parrot.live
```

```
clear; ls -a # showing all folders in root dir
mkdir lorem ipsum dolor
# 3 new directories will have been added to your root folder
rm -rf lorem ipsum dolor
```
