#include <iostream>

struct Node
{
	int data;
	Node* left, *right;

	// constructors
	Node():data(0), left(NULL), right(NULL){}
	Node(int x):data(x), left(NULL), right(NULL){}
	Node(int x, Node* l, Node* r):data(x), left(l), right(r){}
};

Node* Insert(Node* root, int x)
{
	if (root == NULL) // empty tree
		root = new Node(x);

	else if (x <= root->data)
		root->left = Insert(root->left, x);

	else root->right = Insert(root->right, x);

	return root;
}
bool Search(Node* root, int x)
{
	if (root == NULL) return false;
	else if (x == root->data) return true;
	else if (x <= root->data) return Search(root->left, x);
	else return Search(root->right, x);

	return false;
}

int main()
{
	Node* root = NULL;

	root = Insert(root, 15); // first insert will instantiate a root
	Insert(root, 10);
	Insert(root, 20);

	std::cout << Search(root, 15) << std::endl;
	std::cout << Search(root, 1) << std::endl;
	std::cout << Search(root, 10) << std::endl;
	std::cout << Search(root, 20) << std::endl;
	std::cout << Search(root, 30) << std::endl;
}