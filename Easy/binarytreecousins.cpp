/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
      TreeNode *xParent = nullptr;
      TreeNode *yParent = nullptr;
      //Conduct BFS
      queue<TreeNode*> bfsQ;
      bfsQ.push(root);
      while(!bfsQ.empty()) {
        int curSize = bfsQ.size();
        for(int i = 0; i < curSize; i++) {
          TreeNode* curNode = bfsQ.front();
          bfsQ.pop();
          TreeNode *left = curNode->left;
          TreeNode *right = curNode->right;
          if(left != nullptr) {
            if(left->val == x) {
              xParent = curNode;
              if(yParent != nullptr) {
                return xParent != yParent;
              }
            } else if(left->val == y) {
              yParent = curNode;
              if(xParent != nullptr) {
                return xParent != yParent;
              }
            } else {
              bfsQ.push(left);
            }
          }
          if(right != nullptr) {
            if(right->val == x) {
              xParent = curNode;
              if(yParent != nullptr) {
                return xParent != yParent;
              }
            } else if(right->val == y) {
              yParent = curNode;
              if(xParent != nullptr) {
                return xParent != yParent;
              }
            } else {
              bfsQ.push(right);
            }
          }
        }
        if(xParent != nullptr || yParent != nullptr) {
          return false;
        }
      }
      return false;
    }
};