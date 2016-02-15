/**
 * Leetcode problem list 1: two sum.
 * Use map algorithm(stl). 
 *
 * hellfire(asyncloading#163.com)
 * Feb 15th, 2016
 */
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
  public:
    vector<int> twoSum(vector<int>& nums, int target) {
      vector<int> output(2);
      unordered_map<int, int> umap;      

      for (int i = 0; i < nums.size(); i ++)
      {
        if (umap.find(target - nums[i]) != umap.end())
        {
          output[0] = umap[target - nums[i]];
          output[1] = i;
        }
        else
        {
          umap.insert(make_pair(nums[i], i));
        }  
      }
      return output; 
    }
};

int main(int argc, char **argv)
{
  Solution s;
  int arr[] = {2, 7, 11, 15};
  int target = 13;
  vector<int> nums(arr, arr + 3);
  vector<int> output = s.twoSum(nums, target);
  cout << output[0] << output[1] << endl;
}
