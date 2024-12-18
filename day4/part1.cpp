#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include "../utilities/utils.h"

using namespace std;


int main () {
    vector<vector<char>> wordsearch = read_lines_as_vec<char>("input4.txt");
    string permutations = "";
    const int height = wordsearch.size();
    const int width = wordsearch[0].size();

    //forwards and backwards
    for (const auto& line : wordsearch) {
        string left_to_right(line.begin(), line.end());

        permutations.append(left_to_right);
        permutations.append(" ");

    }

    //up and down
    string up_to_down = "";
    for (int j = 0; j < width; j++) {
        for (int i = 0; i < height; i++) {
            up_to_down.push_back(wordsearch[i][j]);
        }
    
        permutations.append(up_to_down);
        permutations.append(" ");
        up_to_down = "";

    }

    //diagonal left to right 
    string ul_to_dr = "";
    //string dr_to_ul = "";
    for(int k = width, l = -height; k >= 0 || l < height; k--, l++) {
        for(int i = max(k,0), j = max(0,l); i < width && j < height; i++, j++){
            ul_to_dr.push_back(wordsearch[j][i]);
        }
        permutations.append(ul_to_dr);
        permutations.append(" ");
        ul_to_dr = "";
    }

    //diagonal right to left
    string dl_to_ur = "";
    for(int k = 1-width, l = 0; k < width || l < height; k++, l++) {
        for(int i = max(k,0), j = min(l,height-1); i < width && j >= 0; i++, j--) {
            dl_to_ur.push_back(wordsearch[j][i]);
        }
        permutations.append(dl_to_ur);
        permutations.append(" ");
        dl_to_ur = "";
    }
    cout << permutations << endl;

    int xmas_count = 0;
    for (unsigned int i = 0; i < permutations.length()-3; i++) {
        string sample = permutations.substr(i,4);
        if (sample == "XMAS" || sample == "SAMX") {
            xmas_count++;
        }
    }

    cout << xmas_count << endl;
}