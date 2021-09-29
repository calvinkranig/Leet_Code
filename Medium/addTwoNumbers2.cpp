#include <iostream>

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* listReverser(ListNode* list) {
  ListNode *curNodePointer = list;
  ListNode *revNodePointer = nullptr;
  while(curNodePointer != nullptr) {
    ListNode *prevNodePointer = revNodePointer;
    revNodePointer = new ListNode(curNodePointer->val, prevNodePointer);
    curNodePointer = curNodePointer->next;
  }
  return revNodePointer;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  //Reverse the two lists
  ListNode* rev1Pointer = listReverser(l1);
  ListNode* rev2Pointer = listReverser(l2);
  //Add the lists togeter
  ListNode* sum = nullptr;
  int carry = 0;
  while(rev1Pointer != nullptr && rev2Pointer != nullptr) {
    ListNode *prevSumPointer = sum;
    int curSum = rev1Pointer->val + rev2Pointer->val + carry;
    carry = curSum/10;
    int remainder = curSum%10;
    sum = new ListNode(remainder, prevSumPointer);
    rev1Pointer = rev1Pointer->next;
    rev2Pointer = rev2Pointer->next;
  }
  //Add rest of rev1
  while(rev1Pointer != nullptr) {
    ListNode *prevSumPointer = sum;
    int curSum = rev1Pointer->val + carry;
    carry = curSum/10;
    int remainder = curSum%10;
    sum = new ListNode(remainder, prevSumPointer);
    rev1Pointer = rev1Pointer->next;
  }
  //Add rest of rev2
  while(rev2Pointer != nullptr) {
    ListNode *prevSumPointer = sum;
    int curSum = rev2Pointer->val + carry;
    carry = curSum/10;
    int remainder = curSum%10;
    sum = new ListNode(remainder, prevSumPointer);
    rev2Pointer = rev2Pointer->next;
  }
  
  if(carry > 0) {
    ListNode *prevSumPointer = sum;
    sum = new ListNode(1, prevSumPointer);
  }
  
  return sum;
}

ListNode* create_test(int* numList) {
  
}

int main()
{
  std::cout << "Hello World";

  return 0;
}
