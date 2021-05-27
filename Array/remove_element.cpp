/* ************************************************************************
> File Name:     remove_element.cpp
> Author:        suzol
> Created Time:  Tue 18 May 2021 07:43:34 PM CST
> Description:   移除数组中指定的元素
 ************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int removeElement(vector<int >& nums, int val);

};

int Solution::removeElement(vector<int >& nums, int val) {
    int fast = 0;    //fast遇到!=val的值赋给slow
    int slow = 0;    //fast遇到==val, slow停止移动一次

    while (fast != nums.size() -1) {
        if (nums[fast] != val) {
            nums[slow++] = nums[fast++];
        } else {
            fast ++;
        }
    }

    return slow;

}

int main(int argc, char **argv) {
    
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(6);
    nums.push_back(9);
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(7);
    nums.push_back(5);
    nums.push_back(8);
    nums.push_back(1);

    Solution s;
    int length = 0;
    length = s.removeElement(nums, 1);

    cout<< length<<endl;

    return 0;
}

