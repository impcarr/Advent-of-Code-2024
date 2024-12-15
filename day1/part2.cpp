#include <iostream>
#include <fstream>
#include <queue>
#include <map>
using namespace std;

int main() {
    string current_line;

    vector<int> left_vec = {};
    map<int,int> right_map;

    ifstream In_File("input1.txt");
    while (getline (In_File, current_line)) {
        int first_space = current_line.find_first_of(' ');
        int second_space = current_line.find_last_of(' ');

        int first_num = atoi(current_line.substr(0, first_space).c_str());
        int second_num = atoi(current_line.substr(second_space, current_line.size()).c_str());

        left_vec.push_back(first_num);

        if(right_map[second_num] > 0) {
            right_map[second_num] = right_map[second_num] + 1;
        }
        else {
            right_map.insert_or_assign(second_num, 1);
        }
    }

    int similarity = 0;
    while (!left_vec.empty()) {
        int left_num = left_vec.back();
        
        similarity += right_map[left_num]*left_num;
        
        left_vec.pop_back();
    }

    cout << similarity << endl;

    return 0;
}