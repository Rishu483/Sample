#include <iostream>
#include <map>
using namespace std;

struct node
{
    int val;
    node *left;
    node *right;
    node *parent;

    node(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
};

node *insert(node *root, int x)
{
    if (root == NULL)
        return new node(x);
    if (x < root->val)
    {
        root->left = insert(root->left, x);
        root->left->parent = root;
    }
    else if (x > root->val)
    {
        root->right = insert(root->right, x);
        root->right->parent = root;
    }
    return root;
}

node *searcher(node *root, int num)
{
    if (root->val == num || root == NULL)
        return root;
    if (num < root->val)
        return searcher(root->left, num);
    return searcher(root->right, num);
}

node *LCA(node *root, int n1, int n2)
{
    node *fNode = searcher(root, n1);
    node *sNode = searcher(root, n2);

    map<node *, bool> ancestors;
    while (fNode != NULL)
    {
        ancestors[fNode] = true;
        fNode = fNode->parent;
    }

    while (sNode != NULL)
    {
        if (ancestors.find(sNode) != ancestors.end())
            return sNode;
        sNode = sNode->parent;
    }

    return NULL;
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

    int n1 = 24, n2 = 26;
    node *common = LCA(root, n1, n2);
    if (common)
        cout << "Lowest common ancestor of " << n1 << " & " << n2 << " : " << common->val << endl;
    else
        cout << "Lowest common ancestor is not Exsit!" << endl;
}