#include <iostream>

struct Node
{
int data;
Node* left, *right;

Node():data(0), left(NULL), right(NULL){}
Node(int x):data(x), left(NULL), right(NULL){}
Node(int x, Node* l, Node* r):data(x), left(l), right(r){}
};

Node* Insert(Node* root, int x)
{
if(root==NULL) root = new Node(x);
else if(x<=root->data) root->left = Insert(root->left, x);
else root->right=Insert(root->right, x);
return root;
}
Node* inorder_successor(Node* )
{
}
int main()
{
Node* root=NULL;
root=Insert(root, 12);
Insert(root, 5);
Insert(root, 3);
Insert(root, 7);
Insert(root, 1);
Insert(root, 9);
Insert(root, 15);
Insert(root, 13);
Insert(root, 17);
Insert(root, 16);
Insert(root, 18);

return 0;

}