/**
 * Leetcode problem 22: generate parentheses.
 * Use backtracking.
 *
 * hellfire (asyncloading#163.com)
 * Mar 5th, 2016
 */
#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    void backtrack(int left, int right, string str, vector<string>& output)
    {
      if (right == 0)
      {
        output.push_back(str);
        return;  
      }
      if (left == right)
      {
        backtrack(left - 1, right, str + "(", output);
        return;
      }
      if (left > 0)
      {
        backtrack(left - 1, right, str + "(", output);
      }
      backtrack(left, right - 1, str + ")", output);
    }

    vector<string> generateParenthesis(int n) {
      vector<string> output;
      backtrack(n, n, "", output);
      return output;    
    }
};

int main(int argc, char **argv)
{
  Solution s;
  vector<string> output = s.generateParenthesis(10);
  for (int i = 0; i < output.size(); i ++)
  {
    cout << output[i] << endl;
  }
  cout << output.size() << endl;
}
