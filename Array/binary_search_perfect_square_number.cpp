/*
 * Binary Search
 * Author: suzol
 * Description:Leetcode_367
 * Date:2021/05/16
 * Note:计算 x 为完全平方数
 * */

#include <iostream>
using namespace std;

/*
 * @summary calculate x is a Perfect square number
 * @author suzol
 * @version 1.0
 * @description:
 * @date:2021/05/16
 * */
class Solution {
public:
    int isPerfectSquare(int x);
};

int Solution::isPerfectSquare(int x)
{
    int left = 0;
    int right = x;

    while (left <= right) {
        int mid = left + (right - left)/2;
        if (x/mid < mid) {
            right = mid - 1;   
        } else if (x/mid > mid) {
            left = mid + 1;
        } else {
            if (mid * mid == x)
                return true;
            break;
        }
    }

    return false;
}

int main() {
   Solution s;
   int result;
   result = s.isPerfectSquare(18);
   cout<<"close_index = "<< result<<endl;

   result = s.isPerfectSquare(36);
   cout<<"open_index = "<< result<<endl;
                                
   return 0;
}