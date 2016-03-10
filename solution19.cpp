/**
 * Leetcode problme 19: remove nth node from end of list.
 * Use two pointers. 
 *
 * hellfire (asyncloading#163.com)
 * Mar 6th, 2016
 */
#include<cstdio>
#include<cstdlib>

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      if (head == NULL || head -> next == NULL)
      {
        return NULL;
      }
      /* Two pointers p and q.*/
      ListNode *p, *q;

      p = head;
      q = head;
      /* P go n step. */
      while (n > 0)
      {
        p = p -> next; 
        n --;
      }
      
      if (p == NULL)
      {
        return head -> next;
      }

      while (p -> next != NULL)
      {
        p = p -> next;
        q = q -> next;
      }

      /* Delete ListNode*/
      ListNode *tmp;
      tmp = q -> next;
      q -> next = tmp -> next;
      free(tmp);
      return head;    
    }
};

int main(int argc, char **argv)
{
  Solution s;
  ListNode *l1 = new ListNode(1);
  ListNode *l2 = new ListNode(2);

  l1 -> next = l2;
  ListNode *p = s.removeNthFromEnd(l1, 2);
  while (p != NULL)
  {
    printf("%d\n", p -> val);
    p = p -> next;
  }
}

