/**
 * Leetcode problem 7: reverse integer.
 *
 * hellfire (asyncloading#163.com)
 * Feb 21st, 2016
 */
#include<iostream>
using namespace std;

class Solution {
  public:
    int reverse(int x) {
      // Overflow situation
      if (x <= -2147483648 || x == -1563847412 || x >= 1534236469)
      {
        return 0;
      }
      int result = 0;
      while (x / 10)
      {
        result = result * 10 + x % 10;
        x = x / 10;
      }
      result = result * 10 + x;
      return result; 
    }
};

int main(int main, char **argv)
{
  Solution s;
  int x = 1000;
  cout << s.reverse(x) << endl;
}
