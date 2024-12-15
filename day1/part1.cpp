#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

int main() {
    string current_line;

    priority_queue<int> left_queue;
    priority_queue<int> right_queue;

    ifstream In_File("input1.txt");
    while (getline (In_File, current_line)) {
        int first_space = current_line.find_first_of(' ');
        int second_space = current_line.find_last_of(' ');

        int first_num = atoi(current_line.substr(0, first_space).c_str());
        int second_num = atoi(current_line.substr(second_space, current_line.size()).c_str());

        left_queue.push(first_num);
        right_queue.push(second_num);

    }
    int distance_sum = 0;
    while (!left_queue.empty()) {
        int left_num = left_queue.top();
        int right_num = right_queue.top();
        int distance = abs(left_num-right_num);
        
        distance_sum += distance;
        
        left_queue.pop();
        right_queue.pop();
    }

    cout << distance_sum << endl;

    return 0;
}