/*
 * Binary Search
 * Author: suzol
 * Description:Leetcode_69
 * Date:2021/05/16
 * Note:计算 x的平方根
 * */

#include <iostream>
using namespace std;

/*
 * @summary calculate the square root of x
 * @author suzol
 * @version 1.0
 * @description:
 * @date:2021/05/16
 * */
class Solution {
public:
    int mySqrt_brute_force(int x);
    int mySqrt_binary_search(int x);
	int mySqrt(int x);
};

int Solution::mySqrt_brute_force(int x)
{
    if (x == 0) {
		return 0;
	}
	
	int m = 1;
	for (; x/m >= m; m++);
	return m-1;

}

int Solution::mySqrt_binary_search(int x)
{

    int left = 0;
    int right = x;
    int result = 0;
    
    if (x <= 1) {
        return x;
    }

    while (left <= right) {
        int middle = left + (right - left)/2;
        if (x / middle < middle) { //平方根在middle左边
            right = middle -1;
        }else{                     //平方根在middle右边
            result = middle;       //先保留整数部分
            left = middle +1;
        }
    }
    return result;
}

/*
int Solution::mySqrt(int x)
{
  // To be written
 
}
*/

int main() {
   Solution s;
   int result;
   result = s.mySqrt_binary_search(18);
   cout<<"close_index = "<< result<<endl;

   result = s.mySqrt_binary_search(5);
   cout<<"open_index = "<< result<<endl;
                                
   return 0;
}