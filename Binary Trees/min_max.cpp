#include <iostream>
#define TREE_EMPTY -1000

struct Node
{
	int data;
	Node* left, * right;

	// constructors
	Node():data(0), left(NULL), right(NULL){}
	Node(int x):data(x), left(NULL), right(NULL){}
	Node(int x, Node* l, Node* r):data(x), left(l), right(r){}
};

Node* Insert(Node* root, int x)
{
	if (root == NULL) root = new Node(x);
	else if (x <= root->data) root->left = Insert(root->left, x);
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

int Max(Node* root)
{
	if (root == NULL)
	{
		std::cout << "Tree is empty." << std::endl;
		return TREE_EMPTY;
	}

	Node* r;
	for (r = root; r->right != NULL; r = r->right);
	return r->data;
}

int Min(Node* root)
{
	if (root == NULL)
	{
		std::cout << "Tree is empty" << std::endl;
		return TREE_EMPTY;
	}

	Node* r;
	for (r = root; r->left != NULL; r = r->left);
	return r->data;
}

int MaxRecur(Node* root)
{
	if (root == NULL)
	{
		std::cout << "Tree is empty." << std::endl;
		return TREE_EMPTY;
	}

	else if (root->right == NULL) return root->data;
	else return MaxRecur(root->right);
}
int MinRecur(Node* root)
{
	if (root == NULL)
	{
		std::cout << "Tree is empty." << std::endl;
		return TREE_EMPTY;
	}

	else if (root->left == NULL) return root->data;
	else return MinRecur(root->left);
}

int main()
{
	Node* root = NULL;

	root = Insert(root, 10);
	Insert(root, 30);
	Insert(root, 40);
	Insert(root, 5);
	Insert(root, 5);
	Insert(root, 7);

	std::cout << Max(root) << std::endl;
	std::cout << MaxRecur(root) << std::endl;
	std::cout << Min(root) << std::endl;
	std::cout << MinRecur(root) << std::endl;
}