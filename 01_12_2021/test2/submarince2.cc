#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

int main(int argc, char* argv[]) {
  std::ifstream inputfile(argv[1]);
  std::ofstream os(argv[2]);
  std::string line;

  std::vector<int> measurements_vec;
  std::vector<int> measure_sums;
  int counter = 0;

  while(getline(inputfile,line)) {
    measurements_vec.emplace_back(std::stoi(line));
  }
  int first_sum = measurements_vec[0] + measurements_vec[1] + measurements_vec[2];
  measure_sums.emplace_back(first_sum);
  for (int i = 3; i < measurements_vec.size(); i++) {
    measure_sums.emplace_back(measurements_vec[i] + measurements_vec[i - 1] + measurements_vec[i -2]);
  }
  os << measure_sums[0] << "(N/A - no previous sum)\n";
  for (int j = 1; j < measure_sums.size(); j++) {
    if (measure_sums[j] == measure_sums[j - 1] ) {
      os << measure_sums[j] << "(No change)\n";
    }
    if (measure_sums[j] < measure_sums[j - 1]) {
      os << measure_sums[j] << "(Decrease)\n";
    }
    if (measure_sums[j] > measure_sums[j - 1]) {
      os << measure_sums[j] << "(Increase)\n";
      counter++;
    }
  }
  std::cout << "The measure increase " << counter << " times\n"; 
}