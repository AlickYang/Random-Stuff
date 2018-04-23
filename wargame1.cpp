#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
int main() {
  //Compile with: g++ -Werror -Wall -O2 -std=c++14 -o wg1 wargame1.cpp
  //Crypto: TGPRGWTADEKI HI3OYNODONAT ES4LOCIINTB} FC4LURSDTHO_ LO1IRYAEEIU_ AM{NOPBAVNT_
  //Read all inputs ctrl-D to end input 
  std::string input;
  std::vector<std::string> vec;
  int len = 0;
  while (std::getline(std::cin, input, ' ')) {
    input.erase(std::remove(input.begin(), input.end(), '\n'), input.end());
    if (input.size() != 0) {
      vec.push_back(input);
      len = input.size();
    }
  }

  //Check that input has all strings of same size
  //Iterate through vector of strings and check length 
  for (auto it = vec.cbegin(); it != vec.cend(); ++it) {
    if (it->size() != len) {
      std::cerr << "Lengths not equal\n";
      exit(0);
    }
  }
  //Compile flag 
  std::string flag;
  for (int pos = 0; pos < len; ++pos) {
    for (auto it = vec.cbegin(); it != vec.cend(); ++it) {
      flag += it->at(pos);
    }
  }
  std::cout << "flag is: " << flag << "\n";
  return 0;
}
