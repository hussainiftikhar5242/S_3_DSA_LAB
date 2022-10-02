#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> rightSideView(TreeNode* root) 
{
    vector<int> result;
    queue<TreeNode*> myQueue;
    myQueue.push(root);
    if(!root) return result;
    while (!myQueue.empty())
    {
        vector<int> helper;
        int n = myQueue.size();
        for(int i = 0; i < n; i++)
        {
            TreeNode* node = myQueue.front();
            myQueue.pop();
            helper.push_back(node->val);
            if(node->left) myQueue.push(node->left);
            if(node->right) myQueue.push(node->right);
        }
        result.push_back(helper.back());
    }
    return result;
}