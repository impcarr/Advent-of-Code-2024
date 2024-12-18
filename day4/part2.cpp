#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include "../utilities/utils.h"

using namespace std;

int check_x(int row, int col, vector<vector<char>> grid) {
    int valid = 1;
    if(!((grid[row-1][col-1] =='M' && grid[row+1][col+1] == 'S') || (grid[row-1][col-1] =='S' && grid[row+1][col+1] == 'M'))) {
        cout << "first" << endl;
        valid = 0;
    }
    if(!((grid[row-1][col+1] == 'M' && grid[row+1][col-1] == 'S') || (grid[row-1][col+1] == 'S' && grid[row+1][col-1] == 'M'))) {
        cout << "second" << endl;
        valid = 0;
    }
    cout << valid << endl;
    return valid;
}

int main () {
    vector<vector<char>> wordsearch = read_lines_as_vec<char>("input4.txt");
    string permutations = "";
    const int height = wordsearch.size();
    const int width = wordsearch[0].size();

    int xmas_count = 0;
    for (int j = 1; j < height-1; j++) {
        for(int i = 1; i < width-1; i++) {
            if(wordsearch[j][i] == 'A') {
                cout << "calling check_x at row " << j << " column " << i << endl;
                xmas_count += check_x(j,i,wordsearch);
                //cout << xmas_count << endl;
            }
        }
    }

    cout << xmas_count << endl;
}