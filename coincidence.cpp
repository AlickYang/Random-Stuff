#include <iostream>
#include <iomanip> 
#include <fstream>
#include <array>
#include <string>

//Compile with g++ -Werror -Wall -O2 -std=c++14 -o frequency

int main(int argc, char *argv[]) {
  if (argc < 1) std::cerr << "Usage: ./frequency <fileName>\n";
  //Open file
  std::ifstream myfile;
  std::string fileName = argv[1];
  std::cout << argv[1];
  std::string line;

  std::array<int, 26> frequencyIndex;
  frequencyIndex.fill(0);
  double numCharacters = 0;
  myfile.open(fileName);
  //Process file
  if (myfile.is_open()) {
    std::cout << ": file is open\n";    
    while (std::getline(myfile, line)) {
      numCharacters += line.size();
      //Process string
      for (auto it = line.cbegin(); it != line.cend(); ++it) {
        std::tolower(*it);
        int val = *it - 'a';
        if (val > 0 && val < 26) { //Check to ensure it is alphabet character
          ++frequencyIndex[val];
        }
      }
    }
  }
  //Display stats
  int counter = 0;
  double numerator = 0;
  for (auto it = frequencyIndex.cbegin(); it != frequencyIndex.cend(); ++it) {
    numerator += ((*it)*(*it-1));
    double frequency = static_cast<double>(*it/numCharacters)*100;
    std::cout << char('A'+counter) << ": " << *it << " -> " << std::setprecision(2) << frequency << "% \n";
    ++counter;
  }
  //Calculating frequency:
  
  double incidenceCoincidence = numerator/(numCharacters * (numCharacters-1));
  std::cout << incidenceCoincidence << "\n";
  myfile.close();
  return 0;
}


