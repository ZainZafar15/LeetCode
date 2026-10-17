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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* nn = new TreeNode(val);
        if (root == nullptr)
        {
            root = nn;
        }
        else
        {
            TreeNode* parent = nullptr;
            TreeNode* curr = root;
            while (curr != nullptr)
            {
                parent = curr;
                if (curr->val < val)
                {
                    curr = curr->right;
                }
                else if (curr->val > val)
                {
                    curr = curr->left;
                }
            }
            if (parent->val > val)
            {
                parent->left = nn;
            }
            else if (parent->val < val)
            {
                parent->right = nn;
            }
        }
        return root;
    }
};