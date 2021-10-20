#include <iostream>
#include <queue>
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

void Invert_Recursive(Node* root)
{
	// pre-order traversal recursive
	if (root == NULL) return;
	std::swap(root->left, root->right);
	Invert_Recursive(root->left);
	Invert_Recursive(root->right);
}

void Invert_Iterative(Node* root)
{
	// using an iterative pre-order traversal
	std::stack<Node*> s;
	s.push(root);
	while (!s.empty())
	{
		Node* curr = s.top();
		std::swap(curr->left, curr->right);
		s.pop();

		if (curr->left)s.push(curr->left);
		if (curr->right)s.push(curr->right);
	}
}

void Invert_LevelOrder(Node* root)
{
	// similar approach, this time using a level order traversal
	std::queue<Node*> q;
	q.push(root);
	
	while (!q.empty())
	{
		Node* t = q.front();
		std::swap(t->left, t->right);
		if (t->left)q.push(t->left);
		if (t->right)q.push(t->right);
		q.pop();
	}
}

void level_order_traversal(Node* root)
{
	std::queue<Node*> q;
	q.push(root);
	while (!q.empty())
	{
		Node* curr = q.front();
		std::cout << curr->data << " ";
		if (curr->left != NULL)q.push(curr->left);
		if (curr->right != NULL) q.push(curr->right);
		q.pop();
	}
	std::cout << "\n";
}

int main()
{
	Node* root = NULL;
	root = Insert(root, 12);
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

	level_order_traversal(root);
	Invert_Recursive(root);
	level_order_traversal(root);
	Invert_Iterative(root);
	level_order_traversal(root);
	Invert_LevelOrder(root);
	level_order_traversal(root);

	return 0;
}