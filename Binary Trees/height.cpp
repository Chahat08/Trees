#include <iostream>
#include <algorithm>

struct Node
{
	int data;
	Node* left, * right;

	// constructors
	Node() :data(0), left(NULL), right(NULL) {}
	Node(int x) :data(x), left(NULL), right(NULL) {}
	Node(int x, Node* l, Node* r) :data(x), left(l), right(r) {}
};

Node* Insert(Node* root, int x)
{
	if (root == NULL) root = new Node(x);
	else if (x <= root->data) root->left = Insert(root->left, x);
	else root->right = Insert(root->right, x);

	return root;
}
int height(Node* root)
{
	if (root == NULL) return -1;
	return std::max(height(root->left), height(root->right)) + 1;
}
int main()
{
	Node* root = NULL;
	root = Insert(root, 10);
	Insert(root, 10);
	Insert(root, 20);
	Insert(root, 5);
	Insert(root, 3);
	Insert(root, 13);
	Insert(root, 8);
	Insert(root, 6);
	Insert(root, 8);
	std::cout << height(root) << std::endl;
}