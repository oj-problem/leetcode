/**
 * Leetcode Problem 3: Longest Substring Without Repeating Characters
 * Hash ( character -> ASCII)
 *
 * hellfire (asyncloading#163.com)
 * Feb 16th, 2016
 */
#include<iostream>

using namespace std;

class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
      int max_len = 0;
      int visited[256];     
      int str_size = s.length();

      if (str_size == 1)
      {
        return 1;
      }

      for (int i = 0; i < str_size; i ++)
      {
        memset(visited, 0, sizeof(visited));      /* Clear memory visited array. */
        visited[s[i]] = 1;
        bool has_repeated = false;
        for (int j = i + 1; j < str_size; j ++)
        {
          if (visited[s[j]] == 0)
          {
            visited[s[j]] = 1;
          }
          else
          {
            has_repeated = true;
            if (j - i > max_len)
            {
              max_len = j - i;
            }
            break;
          }
        }
        if (!has_repeated)
        {
          if (max_len < str_size - i)
          {
            max_len = str_size - i;
          }
        }            
      }
      return max_len;
    }
};

int main(int argc, char **argv)
{
  Solution s;
  string str = "abcabcabcbacde";
  int max_len = s.lengthOfLongestSubstring(str);
  cout << max_len << endl;  
}
