/**
 * Leetcode problem 23: merge k sorted list.
 *
 * hellfire (asyncloading#163.com)
 * Mar 1st, 2016
 */
#include<iostream>
#include<vector>

using namespace std;


/**
 * Definition for singly-linked list.
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
  public:
      ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL)
        {
            return l2;
        }
        if (l2 == NULL)
        {
            return l1;
        }
        ListNode *l3;
        if (l1 -> val < l2 -> val)
        {
            l3 = l1;
            l3 -> next = mergeTwoLists(l1 -> next, l2);
        }
        else
        {
            l3 = l2;
            l3 -> next = mergeTwoLists(l1, l2 -> next);
        }
        return l3;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
      int size = lists.size();
      if (size == 0)
      {
        return NULL;
      }
      if (size == 1)
      {
        return lists[0];
      }
      int mid = (size - 1) / 2 ;

      vector<ListNode*> lists1(lists.begin(), lists.begin() + mid + 1);
      vector<ListNode*> lists2(lists.begin() + mid + 1, lists.end());
      ListNode *l1 = mergeKLists(lists1);
      ListNode *l2 = mergeKLists(lists2);

      return mergeTwoLists(l1, l2);
    }
};


int main(int argc, char **argv)
{
  Solution s;

  ListNode *l1 = new ListNode(2);
  ListNode *l2 = new ListNode(1);
  ListNode *l3 = new ListNode(4);
  ListNode *l4 = new ListNode(3);

  vector<ListNode*> lists;
  lists.push_back(l1);
  lists.push_back(l2);
  lists.push_back(l3);
  lists.push_back(l4);

  ListNode *p = s.mergeKLists(lists);

  while (p != NULL)
  {
    cout << p -> val << endl;
    p = p -> next;
  }
}
