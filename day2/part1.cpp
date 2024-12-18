#include <iostream>
#include <queue>
#include <fstream>
#include <set>
#include "../utilities/utils.h"

using namespace std;

bool is_safe(const vector<int> &row) {
    if(row.size() == 1) {
        return true;
    }
    else {
        set<int> row_set = {};
        set<int> inc_set = {1,2,3};
        set<int> dec_set = {-1,-2,-3};
        for(unsigned int i = 1; i < row.size(); i+=1) {
            row_set.insert(row[i-1]-row[i]);
        }
        
        // logical nxor
        if (!(!is_subset_of(row_set, inc_set) != !is_subset_of(row_set, dec_set))) {
            return false;
        }
    return true;

    }
}

int main () {
    vector<vector<int>> data = read_lines_as_vec<int>("input2.txt");
    int safe_count = 0;
    for (const vector<int>& row : data) {
        if(is_safe(row)){
            safe_count += 1;
        }
    }
    cout << safe_count << endl;
}