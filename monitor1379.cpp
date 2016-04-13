#include "monitor1379.h"
#include <iostream>

using namespace std;

void display(vector<int> nums) {
    for(size_t i = 0; i < nums.size() - 1; i++)
        cout << nums[i] << ", ";
    cout << nums[nums.size() - 1] << endl;
}

