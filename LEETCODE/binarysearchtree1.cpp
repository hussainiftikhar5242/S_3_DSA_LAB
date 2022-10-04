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
    TreeNode* searchBST(TreeNode* root, int val) {
        
        TreeNode* node=root;        
        if(root == NULL)
        {
            return NULL;
        }
        else if(root->val  ==  val)
        {
            return root;
        }
        else
        {
             while(node != NULL)
            {
                if(node->val > val)
                {

                    if(node->val == val)
                    {
                        return node;
                    }
                    node=node->left;
                 }
                 else
                 {
                     if(node->val == val)
                    {
                        return node;
                    }
                    node=node->right;
                 }

                    
            }
        }
        return NULL;
        
    }
};