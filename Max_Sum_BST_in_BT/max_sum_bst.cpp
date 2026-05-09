class Solution
{
public:
    int ans = 0;
    struct Info
    {
        bool isBST;
        int mn, mx, sum;
    };
    Info solve(TreeNode *root)
    {
        if (root == NULL)
        {
            return {true, INT_MAX, INT_MIN, 0};
        }
        Info left = solve(root->left);
        Info right = solve(root->right);
        if (left.isBST && right.isBST && left.mx < root->val && root->val < right.mn)
        {
            int currSum = left.sum + right.sum + root->val;
            ans = max(ans, currSum);
            return {
                true, min(root->val, left.mn),
                max(root->val, right.mx), currSum

            };
        }
        return {false, INT_MIN, INT_MAX, 0};
    }
    int maxSumBST(TreeNode *root)
    {
        solve(root);
        return ans;
    }
};