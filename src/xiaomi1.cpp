#include <iostream>
#include <limits>
#include <numeric>
#include <vector>

using namespace std;

template <class Type>
class ListNode {
 public:
  Type data;
  ListNode<Type> *next;
};

class Solution {
  void reverse(ListNode<int> *head) {
    ListNode<int> *pre = nullptr, *cur = head;
    while (cur != nullptr) {
      ListNode<int> *next = cur->next;
      cur->next = pre;
      pre = cur;
      cur = next;
    }
  }

 public:
  /* Write Code Here */
  ListNode<int> *reverseBetween(ListNode<int> *head, int left, int right) {
    ListNode<int> *dummyHead = new ListNode<int>();
    dummyHead->data = 0;
    dummyHead->next = head;
    ListNode<int> *l = head, *r = head, *pre = dummyHead;
    for (int i = 0; i < left - 1; i++) pre = pre->next;
    for (int i = 0; i < right - 1; i++) r = r->next;

    l = pre->next;
    ListNode<int> *cur = r->next;

    pre->next = nullptr;
    r->next = nullptr;

    reverse(l);
    pre->next = r;
    l->next = cur;

    return dummyHead->next;
  }
};
int main() {
  ListNode<int> *res = NULL;

  int head_size = 0;
  cin >> head_size;

  ListNode<int> *head = NULL, *head_curr = NULL;
  int head_item;
  for (int head_i = 0; head_i < head_size; head_i++) {
    cin >> head_item;

    ListNode<int> *head_temp = new ListNode<int>();
    head_temp->data = head_item;
    head_temp->next = NULL;
    if (head == NULL) {
      head = head_curr = head_temp;
    } else {
      head_curr->next = head_temp;
      head_curr = head_temp;
    }
  }

  int left;
  cin >> left;

  int right;
  cin >> right;

  Solution *s = new Solution();
  res = s->reverseBetween(head, left, right);
  while (res != NULL) {
    cout << res->data << " ";
    res = res->next;
  }
  cout << endl;

  return 0;
}
