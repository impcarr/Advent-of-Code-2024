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
    regex pattern(R"((mul\((-?\d+),(-?\d+)\))|(don't\(\))|(do\(\)))");
    smatch match;
    vector<pair<int, int>> matches;
    bool on = true;

    for(sregex_iterator it = sregex_iterator(input_string.begin(), input_string.end(), pattern); 
        it != sregex_iterator(); it++) {
        match = *it;
        if(on && match[1].matched) {
            matches.push_back(make_pair(stoi(match[2]),stoi(match[3])));
        }
        else if (match[4] == "don't()") {
            on = false;
        }
        else if (match[5] == "do()") {
            on = true;
        }
        
    }
    
    int total = 0; 
    for(pair<int, int> mult : matches) {
        total += mult.first * mult.second;
    }
    
    cout << total << endl;    
    return 0;
}