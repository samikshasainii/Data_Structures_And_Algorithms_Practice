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
int maxdepth(TreeNode* root){
    if(root==nullptr){
        return 0;
    }
    int maximum = 1+ max(maxdepth(root->left),maxdepth(root->right));
    return maximum;
}
    bool isBalanced(TreeNode* root) {
        if(root==nullptr){
            return true;
        }
        int maxleft = maxdepth(root->left);
        int maxright = maxdepth(root->right);

        if(abs(maxleft-maxright)>1){
            return false;
        }
        return isBalanced(root->left)&& isBalanced(root->right);
    }
};