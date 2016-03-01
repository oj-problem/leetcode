/**
 * Leetcode problem 21: merge two sorted list.
 */
#include<iostream>
using namespace std;

/* Definition for singly-linked list.*/
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
};

int main(int argc, char **argv)
{
  Solution s;
  ListNode *l1 = new ListNode(2);

  ListNode *l2 = new ListNode(1);
  
  ListNode *merged = s.mergeTwoLists(l1, l2);
  while (merged !=  NULL)
  {
    cout << merged -> val << endl;
    merged = merged -> next;
  }
}
