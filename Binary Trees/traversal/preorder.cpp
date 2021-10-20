#include <iostream>

struct Node
{
	int data;
	Node* left, * right;

	Node():data(0), left(NULL), right(NULL){}
	Node(int x):data(x), left(NULL), right(NULL){}
	Node(int x, Node* l, Node* r):data(x), left(l), right(r){}
};

Node* Insert(Node* root, int x)
{
	if (root == NULL) root = new Node(x);
	else if(x <= root->data) root->left = Insert(root->left, x);
	else root->right = Insert(root->right, x);

	return root;
}

void preorder_traversal(Node* root)
{
	// data, left, right
	if (root == NULL) return;
	std::cout << root->data << " ";
	preorder_traversal(root->left);
	preorder_traversal(root->right);
}

int main()
{
	Node* root = NULL;
	root = Insert(root, 10);
	root = Insert(root, 10);
	root = Insert(root, 20);
	root = Insert(root, 8);
	root = Insert(root, 13);
	root = Insert(root, 21);
	root = Insert(root, 9);

	preorder_traversal(root);
}