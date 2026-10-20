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
    vector<int> vals;

    void inorder(TreeNode* root) {
        if (root == nullptr)
            return;

        inorder(root->left);
        vals.push_back(root->val);
        inorder(root->right);
    }

    vector<vector<int>> closestNodes(TreeNode* root,
                                     vector<int>& queries) {
        inorder(root);

        vector<vector<int>> ans;

        for (int q : queries) {
            int mn = -1, mx = -1;

            auto it = lower_bound(vals.begin(), vals.end(), q);

            if (it != vals.end() && *it == q) {
                mn = mx = q;
            }
            else {
                if (it != vals.begin())
                    mn = *(it - 1);

                if (it != vals.end())
                    mx = *it;
            }

            ans.push_back({mn, mx});
        }

        return ans;
    }
};