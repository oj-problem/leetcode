/**
 * Leetcode problem 20: valid parentheses.
 *
 * hellfire (asyncloading#163.com)
 * Mar 6th, 2016
 */
#include<iostream>
#include<stack>

using namespace std;

class Solution {
  public:
    bool isValid(string s) {
      stack<char> ch_stack;
      bool is_valid = true;
      for (int i = 0; i < s.length(); i ++)
      {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
          ch_stack.push(s[i]);
        }
        else
        {
          if (!ch_stack.empty())
          {
            char ch_top = ch_stack.top();
            if ((s[i] == ')' && ch_top == '(') || (s[i] == ']' && ch_top == '[') || (s[i] == '}' && ch_top == '{'))
            {
              ch_stack.pop();
            }
            else
            {
              is_valid = false;
              break;
            }
          }
          else
          {
            is_valid = false;
            break;
          }
        }
      }
      if (!ch_stack.empty())
      {
        is_valid = false;
      }
      return is_valid;      
    }
};

int main(int argc, char **argv)
{
  Solution s;
  cout << s.isValid("((");
}
