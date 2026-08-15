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
TreeNode* findMinNode(TreeNode* root){
    while(root->left!=nullptr){
        root = root->left;
    }
    return root;
}
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr){
            return nullptr; //node nt found
        }
        if(key<root->val){
            root->left= deleteNode(root->left,key);
        }
        else if(key>root->val){
            root->right = deleteNode(root->right,key);
        }
        else{//here the condition would basically be val==root->data

        if(root->left==nullptr){
            //if theres a single right child
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right==nullptr){
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        else{
            //two children then find min node on right subtree
            TreeNode* temp = findMinNode(root->right);
            root->val = temp->val;
            root->right=deleteNode(root->right,temp->val);
        }
        }
        return root;
    }
};