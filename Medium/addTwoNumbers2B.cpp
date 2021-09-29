#include <iostream>

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  unsigned long long sum1 = 0;
  ListNode* iter = l1;
  while(iter != nullptr) {
    sum1 *= 10;
    sum1 += iter->val;
    iter = iter->next;
  }
  unsigned long long sum2 = 0;
  iter = l2;
  while(iter != nullptr) {
    sum2 *= 10;
    sum2 += iter->val;
    iter = iter->next;
  }
  unsigned long long sum = sum1+sum2;
  ListNode* ret = nullptr;
  do {
    unsigned short curVal = sum%10;
    sum /= 10;
    ListNode* prevNode = ret;
    ret = new ListNode(curVal,prevNode);
  } 
  while(sum>0);
  return ret;
}

int main()
{
  std::cout << "Hello World";

  return 0;
}
