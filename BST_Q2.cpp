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

void rangePrint(node *root, int min, int max)
{
    if (root == NULL)
        return;

    rangePrint(root->left, min, max);
    if (root->val >= min && root->val <= max)
        cout << root->val << " ";
    rangePrint(root->right, min, max);
}

void impRangePrint(node *root, int min, int max)
{
    if (root == NULL)
        return;
    if (root->val >= min && root->val <= max)
    {
        cout << root->val << " ";
        impRangePrint(root->left, min, max);
        impRangePrint(root->right, min, max);
    }
    else if (root->val < min)
        impRangePrint(root->right, min, max);
    else
        impRangePrint(root->left, min, max);
}

int main()
{
    node *root = new node(28);
    insert(root, 25);
    insert(root, 30);
    insert(root, 33);
    insert(root, 26);
    insert(root, 29);
    insert(root, 35);
    insert(root, 20);
    insert(root, 24);
    insert(root, 40);
    insert(root, 19);

    int min = 25, max = 35;

    cout << "All nodes b/w " << min << " to " << max << " :- ";
    rangePrint(root, min, max);

    cout << endl
         << "All nodes b/w " << min
         << " to " << max << " :- ";
    impRangePrint(root, min, max);
}