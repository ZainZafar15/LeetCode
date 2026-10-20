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
    int ans = 0;

    struct Info {
        bool bst;
        int mn, mx, sum;
    };

    Info solve(TreeNode* root) {
        if (root == nullptr)
            return {true, INT_MAX, INT_MIN, 0};

        Info l = solve(root->left);
        Info r = solve(root->right);

        if (l.bst && r.bst &&
            root->val > l.mx && root->val < r.mn) {

            int sum = l.sum + r.sum + root->val;
            ans = max(ans, sum);

            return {
                true,
                min(root->val, l.mn),
                max(root->val, r.mx),
                sum
            };
        }

        return {false, 0, 0, 0};
    }

    int maxSumBST(TreeNode* root) {
        solve(root);
        return ans;
    }
};