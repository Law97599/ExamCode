#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  struct TreeNode* left;
  struct TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<TreeNode*> traversal(vector<int>& preOrder, int preorderBegin,
                            int preorderEnd, vector<int>& inOrder,
                            int inorderBegin, int inorderEnd) {
  if (preorderBegin == preorderEnd) return {nullptr};

  int rootVal = preOrder[preorderBegin];
  TreeNode* root = new TreeNode(rootVal);

  if (preorderBegin - preorderEnd == 1) return {root};

  vector<TreeNode*> res;

  vector<int> deli;
  for (int i = inorderBegin; i < inorderEnd; i++) {
    if (inOrder[i] == rootVal) {
      deli.push_back(i);
    }
  }

  for (int i = 0; i < deli.size(); i++) {
    int index = deli[i];

    int leftInorderBegin = inorderBegin;
    int leftInorderEnd = index;
    int rightInorderBegin = index + 1;
    int rightInorderEnd = inorderEnd;

    int leftPreorderBegin = preorderBegin + 1;
    int leftPreorderEnd = preorderBegin + 1 + index - inorderBegin;
    int rightPreorderBegin = preorderBegin + 1 + index - inorderBegin;
    int rightPreorderEnd = preorderEnd;

    auto left = traversal(preOrder, leftPreorderBegin, leftPreorderEnd, inOrder,
                          leftInorderBegin, leftInorderEnd);
    auto right = traversal(preOrder, rightPreorderBegin, rightPreorderEnd,
                           inOrder, rightInorderBegin, rightInorderEnd);

    for (auto l : left) {
      for (auto r : right) {
        TreeNode* temp = new TreeNode(rootVal);
        temp->left = l;
        temp->right = r;
        res.push_back(temp);
      }
    }
  }
  return res;
}

vector<TreeNode*> getBinaryTrees(vector<int>& preOrder, vector<int>& inOrder) {
  if (inOrder.size() == 0 || preOrder.size() == 0) return {};
  return traversal(preOrder, 0, preOrder.size(), inOrder, 0, inOrder.size());
}

int main() {
  vector<int> pre = {1, 1, 2};
  vector<int> in = {1, 2, 1};

  getBinaryTrees(pre, in);

  return 0;
}