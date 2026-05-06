class BSTIterator
{
private:
    stack<TreeNode *> st;
    bool reverse;

public:
    BSTIterator(TreeNode *root, bool isReverse)
    {
        reverse = isReverse;
        pushAll(root);
    }

    bool hasNext()
    {
        return !st.empty();
    }

    int next()
    {

        TreeNode *temp = st.top();
        st.pop();

        if (reverse == false)
            pushAll(temp->right);

        else
            pushAll(temp->left);

        return temp->val;
    }

private:
    void pushAll(TreeNode *node)
    {

        while (node != NULL)
        {

            st.push(node);

            if (reverse == false)
                node = node->left;

            else
                node = node->right;
        }
    }
};

class Solution
{
public:
    bool findTarget(TreeNode *root, int k)
    {
        if (root == NULL)
            return false;
        BSTIterator l(root, false);
        BSTIterator r(root, true);
        int i = l.next();
        int j = r.next();
        while (i < j)
        {
            if (i + j == k)
                return true;
            else if (i + j < k)
                i = l.next();
            else
                j = r.next();
        }
        return false;
    }
};