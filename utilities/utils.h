#ifndef UTILS_H
#define UTILS_H

#include<vector>
#include<string>
#include<set>

std::vector<std::vector<int>> read_lines_as_vec(const std::string& filename);

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