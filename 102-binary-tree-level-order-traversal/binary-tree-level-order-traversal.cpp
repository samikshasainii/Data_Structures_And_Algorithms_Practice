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
    vector<vector<int>> vec;
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        if(root==nullptr){
            return vec;
        }
        que.push(root);
        while(!que.empty()){
            int size = que.size();
            vector<int> level;
            for(int i=0; i<size; i++){
            TreeNode* current = que.front();
            level.push_back(current->val); 
            que.pop();

            if(current->left!=nullptr){
                que.push(current->left);
            }
            if(current->right!=nullptr){
                que.push(current->right);
            }
        }
        vec.push_back(level);
        }
        return vec;
    }
};