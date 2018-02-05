/*Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).

If two nodes are in the same row and column, the order should be from left to right.

Examples:

Given binary tree [3,9,20,null,null,15,7],
   3
  /\
 /  \
 9  20
    /\
   /  \
  15   7
return its vertical order traversal as:
[
  [9],
  [3,15],
  [20],
  [7]
]
*/

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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        queue<pair<int, TreeNode*>> q;
        map<int, vector<int>> m;
        vector<vector<int>> res;
        if(!root) {
            return res;
        }
        q.push({0,root});
        while(!q.empty()) {
            TreeNode *top = q.front().second;
            int val = q.front().first;
            q.pop();
            m[val].push_back(top->val);
            if(top->left) {
                q.push({val-1, top->left});
            }
            if(top->right) {
                q.push({val+1, top->right});
            }
        }
        for(auto iter=m.begin(); iter != m.end(); iter++ ) {
            res.push_back(iter->second);
        }
        return res;
        
    }
};