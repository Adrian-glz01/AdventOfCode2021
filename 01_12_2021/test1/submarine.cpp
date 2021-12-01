#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>



int main(int argc, char* argv[]) {
  std::string input_file = argv[1];
  std::ofstream out(argv[2]);
  std::string line;

  std::ifstream file;
  file.open(input_file);
  std::vector<int> measurement_vec;

  while(getline(file,line)) {
    int measurement = std::stoi(line);
    measurement_vec.emplace_back(measurement);
  }
  int first_measure = measurement_vec[0];
  out << first_measure << " (N/A - No previous measurement)\n";

  int counter = 0;

  for (int i = 1; i <= measurement_vec.size(); i++) {
    if (measurement_vec[i-1] < measurement_vec[i]) {
      out << measurement_vec[i] << " (Increased)\n";
      counter++;
    } else {
      out << measurement_vec[i] << " (Decreased)\n";
    }
  }
  std::cout << "The measure increased " << counter << " times.\n";
}