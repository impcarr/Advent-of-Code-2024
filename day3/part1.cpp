#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include "../utilities/utils.h"

using namespace std;


int main () {
    ifstream file("input3.txt");
    string read_string;
    string input_string;
    while (getline(file, read_string)) {
        input_string += read_string;
    }
    regex pattern(R"(mul\((-?\d+),(-?\d+)\))");
    smatch match;
    vector<pair<int, int>> matches;

    for(sregex_iterator it = sregex_iterator(input_string.begin(), input_string.end(), pattern); 
        it != sregex_iterator(); it++) {
        match = *it;
        matches.push_back(make_pair(stoi(match[1]),stoi(match[2])));
    }
    
    int total = 0; 
    for(pair<int, int> mult : matches) {
        total += mult.first * mult.second;
    }
    
    cout << total << endl;    
    return 0;
}