Given a binary search tree and a node in it, find the in-order successor of that node in the BST.

Note: If the given node has no in-order successor in the tree, return null.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        stack<TreeNode*> s;
        TreeNode *temp = root;
        while( temp != NULL ) {
            s.push(temp);
            temp = temp->left;
        }
        TreeNode *prev = NULL;
        while( !s.empty() ) {
            TreeNode *top = s.top();
            if( prev == p ) {
                return top;
            } else {
                prev = top;
            }
            cout << top->val << " ";
            s.pop();
            if( top->right ) {
                TreeNode *t = top->right;
                while( t!= NULL) {
                    s.push(t);
                    t = t->left;
                }
            }
        }
        return NULL;
        
    }
};