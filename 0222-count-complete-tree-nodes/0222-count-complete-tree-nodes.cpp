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
    
    int countNodes(TreeNode* root) {
        TreeNode*curr=root;
        int c=0;
        
        while(curr){
            
            if(curr->left){
                TreeNode*pred=curr->left;
                TreeNode*temp=curr->left;
                while(pred->right) pred=pred->right;
                
                pred->right=curr;
                curr->left=NULL;
                curr=temp;
            }
            else{
                c++;
                curr=curr->right;
            }
        }
        return c;
    }
};