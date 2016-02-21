/**
 * ZigZag conversation.
 *
 * hellfire (asyncloading#163.com)
 * Feb 21st, 2016
 */
#include<iostream>
using namespace std;

class Solution {
  public:
    string convert(string s, int numRows) {
      if (numRows == 1 || s.length() <= numRows)
      {
        return s;
      }

      string res = "";
      int l = 2 * numRows - 2;
      for (int i = 0; i < numRows; i ++)
      {
        for (int j = i, k = 1; j < s.length(); j += l, k ++)
        {
          res += s[j];
          if (i != 0 && i != numRows -1 && l * k - i < s.length())
          {
            res += s[l * k - i];
          }
        }
      }
      return res;
    }
};

int main(int argc, char **argv)
{
  Solution s;
  string str = "PAYPALISHIRING";
  cout << s.convert(str, 3) << endl;
}
