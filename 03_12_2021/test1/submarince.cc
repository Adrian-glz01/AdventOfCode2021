#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <cmath>
#include <string>

void count(std::string chain, std::string& result, std::string& result2) {
  int counter0{0}, counter1{0};
  for (int i = 0; i < chain.size(); i++) {
    if (chain[i] == '0') {
      counter0++;
    } else counter1++;
  }
  counter0>counter1 ? result += "0" : result += "1";
  counter0>counter1 ? result2 += "1" : result2 += "0";
}

int decimal (std::string chain) {
  int returned_value = std::stoi(chain, 0, 2);
  return returned_value;
}

int main(int argc, char* argv[]) {
  std::ifstream input(argv[1]);
  std::string line;

  std::string one,two,three,four,five,six,seven,eight,nine,ten,eleven,twelve;
  std::string binary_num, inverse_num;

  while(std::getline(input,line)) {
    one += std::string(1,line[0]);
    two += std::string(1,line[1]);
    three += std::string(1,line[2]);
    four += std::string(1,line[3]);
    five += std::string(1,line[4]);
    six += std::string(1,line[5]);
    seven += std::string(1,line[6]);
    eight += std::string(1,line[7]);
    nine += std::string(1,line[8]);
    ten += std::string(1,line[9]);
    eleven += std::string(1,line[10]);
    twelve += std::string(1,line[11]);
  }
  count(one,binary_num,inverse_num);
  count(two,binary_num,inverse_num);
  count(three,binary_num,inverse_num);
  count(four,binary_num,inverse_num);
  count(five,binary_num,inverse_num);
  count(six,binary_num,inverse_num);
  count(seven,binary_num,inverse_num);
  count(eight,binary_num,inverse_num);
  count(nine,binary_num,inverse_num);
  count(ten,binary_num,inverse_num);
  count(eleven,binary_num,inverse_num);
  count(twelve,binary_num,inverse_num);
  std::cout << "num: " << binary_num;
  std::cout << " --> " <<decimal(binary_num) << "\n";
  std::cout << "num: " << inverse_num;
  std::cout << " --> " <<decimal(inverse_num) << "\n";

  std::cout << "Result: " << decimal(binary_num) * decimal(inverse_num) << "\n";
}