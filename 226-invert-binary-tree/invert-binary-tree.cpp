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
    TreeNode* invertTree(TreeNode* root) {
        /* for this you have to basically do level order traversal
        but push the right child first and THEN the left child in the q*/

        queue<TreeNode*> q;
        if(root==nullptr){
            return nullptr;
        }
        q.push(root);
        while(!q.empty()){
            TreeNode* current = q.front();
            q.pop();
            swap(current->left,current->right);

            if(current->left != nullptr){
                q.push(current->left);
            }
            if(current->right!=nullptr){
                q.push(current->right);
            }           
        }
        return root;
    }
};