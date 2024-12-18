#ifndef UTILS_H
#define UTILS_H

#include<vector>
#include<string>
#include<set>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

template <typename T>
std::vector<std::vector<T>> read_lines_as_vec(const std::string& filename) {
    std::vector<std::vector<T>> data;
    std::ifstream file(filename);

    if(!file.is_open()) {
        std::cerr << "Error: file " << filename << " failed to open." << std::endl;
    }

    std::string line;
    while(getline(file,line)) {
        std::vector<T> row;
        std::istringstream iss(line);
        T val;

        while (iss >> val) {
            row.push_back(val);
        }
        
        data.push_back(row);
    }
    file.close();
    return data;
}

template <typename T> 
bool is_subset_of(const std::set<T> &a, const std::set<T> &b){
    for (const auto& element : a) {
        if (b.find(element) == b.end()) {
            return false; 
        }
    }
    return true; 
}

#endif