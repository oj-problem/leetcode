/**
 * Leetcode problem 4: Find median of two sorted arrays;
 *
 * hellfire (asyncloading#163.com)
 * Feb 18th, 2016
 */
#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      int m = nums1.size();
      int n = nums2.size();
      int total = m + n;
      if (total % 2 == 0)
      {
        return (findKth(nums1, nums2, total / 2) + findKth(nums1, nums2, total / 2 + 1)) / 2.0;
      }
      else
      {
        return findKth(nums1, nums2, (total + 1) / 2) * 1.0;
      } 
    }
    /* Merge and counting. */
    int findKth(vector<int>& nums1, vector<int>& nums2, int k)
    {
      int p = 0, q = 0;
      for (int i = 0; i < k - 1; i ++)
      {
        /* Handle pointer overflow. */
        if (p >= nums1.size())
        {
          q ++;
        }
        else if (q >= nums2.size())
        {
          p ++;
        }
        else if (nums1[p] <= nums2[q])
        {
          p ++;
        }
        else
        {
          q ++;
        }
      }
      if (p >= nums1.size())
      {
        return nums2[q];
      }
      else if (q >= nums2.size())
      {
        return nums1[p];
      }
      else
      {
        return min(nums1[p], nums2[q]);
      }
    }

};

int main(int argc, char **argv)
{
  int arr1[] = {1, 3, 5, 7, 9};
  int arr2[] = {2, 4, 6};
  vector<int> nums1(arr1 + 0, arr1 + 5);
  vector<int> nums2(arr2 + 0, arr2 + 3);
  Solution s;
  double result = s.findMedianSortedArrays(nums1, nums2);

  cout << result << endl;
}

