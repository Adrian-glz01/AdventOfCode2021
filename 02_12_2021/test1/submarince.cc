#include <iostream>
#include <vector>
#include <fstream>
#include <regex>

int main(int argc, char* argv[]) {
  std::ifstream input(argv[1]);
  std::ofstream os(argv[2]);
  std::string line;

  std::regex reg_forward("forward [0-9]+");
  std::regex reg_down("down [0-9]+");
  std::regex reg_up("up [0-9]+");

  std::regex num("[0-9]+");

  std::smatch matches;

  int counterfor{0}, counterup{0}, counterdown{0};

  int depth{0}, distance{0};

  while (std::getline(input,line)) {
    if (std::regex_search(line,reg_forward)) {
      std::regex_search(line,matches,num);
      distance += std::stoi(matches.str());
      counterfor++;
    }else if (std::regex_search(line,reg_down)) {
      std::regex_search(line,matches,num);
      depth += std::stoi(matches.str());
      counterdown ++;
    }else if (std::regex_search(line,reg_up)) {
      std::regex_search(line,matches,num);
      depth -= std::stoi(matches.str());
      counterup++;
    }
  }
  std::cout << counterfor << " " << counterdown << " " << counterup << "\n";
  int result = distance * depth;
  std::cout << "distance = " << distance << "\n";
  std::cout << "depth = " << depth << "\n";
  std::cout << "result = " << result << "\n";
}