#include <iostream>
#include <stack>

struct Node
{
	int data;
	Node* left, * right;

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

void postorder_traversal(Node* root)
{
	if (root == NULL) return;
	// left, right, data
	postorder_traversal(root->left);
	postorder_traversal(root->right);
	std::cout << root->data << " ";
}
int main()
{
	Node* root = NULL;
	root = Insert(root, 10);
	Insert(root, 20);
	Insert(root, 5);
	Insert(root, 15);
	Insert(root, 25);
	Insert(root, 1);

	postorder_traversal(root);
}