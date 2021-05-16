/*
 * Binary Search
 * Author: suzol
 * Description:Leetcode_35
 * Date:2021/05/16
 * Note:有序(升序)、无重复元素、区间定义为循环不变量
 * */

#include <iostream>
#include <vector>
using namespace std;

/*
 * @summary Binary search keeps loop invariants
 * @author suzol
 * @version 1.0
 * @description:[1]Close left and Close right
 *              [2]Close left and Open right
 * @date:2021/05/16
 * */
class Solution {
public:
    int searchInsert_close(vector<int>& nums, int target);
    int searchInsert_open(vector<int>& nums, int target);
};

int Solution::searchInsert_close(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size()-1;

    while(left<=right)
    {
        int middle = left + (right-left)/2;
        if(nums[middle] > target){
            right = middle - 1;    //降序数组改为 left = middle + 1
        }else if(nums[middle] < target){
            left = middle + 1;     //降序数组改为 right = middle - 1
        }else{
            return middle;
        }
    }
    return left > right ? left : right;
}

int Solution::searchInsert_open(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size();

    while(left < right)
    {
        int middle = left + (right-left)/2;
        if(nums[middle] > target){
            right = middle;
        }else if(nums[middle] < target){
            left = middle + 1;
        }else{
            return middle;
        }
    }
    return left > right ? left : right;
}

int main() {
    int index = -1;

    vector<int > nums;
    nums.push_back(-1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(5);
    nums.push_back(9);
    nums.push_back(12);
    nums.push_back(15);

    Solution s;

    index = s.searchInsert_close(nums,18);
    cout<<"close_index = "<< index<<endl;

    index = s.searchInsert_open(nums,0);
    cout<<"open_index = "<< index<<endl;

}