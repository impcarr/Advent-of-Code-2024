#include "utils.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

std::vector<std::vector<int>> read_lines_as_vec(const std::string& filename) {
    std::vector<std::vector<int>> data;
    std::ifstream file(filename);

    if(!file.is_open()) {
        std::cerr << "Error: file " << filename << " failed to open." << std::endl;
    }

    std::string line;
    while(getline(file,line)) {
        std::vector<int> row;
        std::istringstream iss(line);
        int number;

        while (iss >> number) {
            row.push_back(number);
        }
        
        data.push_back(row);
    }
    file.close();
    return data;
}

//template <typename T>
