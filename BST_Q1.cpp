#include <iostream>
using namespace std;

struct node
{
    int val;
    node *left;
    node *right;

    node(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};

node *insert(node *root, int x)
{
    if (root == NULL)
        return new node(x);
    if (x < root->val)
        root->left = insert(root->left, x);
    else if (x > root->val)
        root->right = insert(root->right, x);
    return root;
}

node *minValue(node *root)
{
    if (root->left == NULL)
        return root;
    return minValue(root->left);
}

node *maxValue(node *root)
{
    if (root->right == NULL)
        return root;
    return maxValue(root->right);
}

node *searcher(node *root, int num)
{
    if (root->val == num || root == NULL)
        return root;
    if (num < root->val)
        return searcher(root->left, num);
    return searcher(root->right, num);
}

node *successor(node *root, int num)
{
    node *findNum = searcher(root, num);
    if (findNum->right != NULL)
        return minValue(findNum->right);

    node *succ = NULL;
    while (root->val != findNum->val)
    {
        if (root->val > findNum->val)
        {
            succ = root;
            root = root->left;
        }
        else
            root = root->right;
    }
    return succ;
}

node *predecessor(node *root, int num)
{
    node *findNum = searcher(root, num);
    if (findNum->left != NULL)
        return maxValue(findNum->left);

    node *pre = NULL;
    while (root->val != findNum->val)
    {
        if (root->val > findNum->val)
            root = root->left;
        else
        {
            pre = root;
            root = root->right;
        }
    }
    return pre;
}

int main()
{
    node *root = new node(18);
    insert(root, 15);
    insert(root, 20);
    insert(root, 13);
    insert(root, 16);
    insert(root, 19);
    insert(root, 25);
    insert(root, 10);
    insert(root, 14);
    insert(root, 30);
    insert(root, 9);

    node *min = minValue(root);
    cout << "Minimum value : " << min->val << endl;

    node *max = maxValue(root);
    cout << "Maximum value : " << max->val << endl;

    int num1 = 18;
    node *succ = successor(root, num1);
    if (succ)
        cout << "Successor of " << num1 << " : " << succ->val << endl;
    else
        cout << "Successor of " << num1 << " is not Exist!" << endl;

    int num2 = 15;
    node *pre = predecessor(root, num2);
    if (pre)
        cout << "Predecessor of " << num2 << " : " << pre->val << endl;
    else
        cout << "Predecessor of " << num2 << " is not Exist!" << endl;
}