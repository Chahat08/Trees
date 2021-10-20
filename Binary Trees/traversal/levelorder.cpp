#include <iostream>
#include <vector>
#include <queue>
#define MAX_LEN 10

struct Node
{
	int data;
	Node* left, * right;

	// constructors
	Node() :data(0), left(NULL), right(NULL) {}
	Node(int x) :data(x), left(NULL), right(NULL) {}
	Node(int x, Node* l, Node* r) :data(x), left(l), right(r) {}
};

struct Queue
{
	std::vector<Node*> que;
	int front = -1, end = -1;

	Queue() { que.resize(MAX_LEN); }

	void Enqueue(Node* n) // can only insert at end
	{
		if (end == MAX_LEN - 1) return;
		
		que[++end] = n;
		if (front == -1) front++;
	}
	Node* Dequeue() // can only delete from front
	{
		// if (front == -1) return NULL;

		return que[front++];
		if (front == -1) end--;
	}
	bool isEmpty()
	{
		if (front > end) return true;
		return false;
	}
};

Node* Insert(Node* root, int x)
{
	if (root == NULL) root = new Node(x);
	else if (x <= root->data) root->left = Insert(root->left, x);
	else root->right = Insert(root->right, x);

	return root;
}
void level_order_traversal_myQ(Node* root)
{
	Queue q;
	q.Enqueue(root);

	while (!q.isEmpty())
	{
		Node* n = q.Dequeue();
		std::cout << n->data << " ";
		if (n->left != NULL) q.Enqueue(n->left);
		if (n->right != NULL) q.Enqueue(n->right);
	}
	std::cout << std::endl;
}
void level_order_traversal(Node* root)
{
	std::queue<Node*> q;
	q.push(root);

	while (!q.empty())
	{
		Node* n = q.front();
		std::cout << n->data << " ";
		q.pop();
		if (n->left != NULL) q.push(n->left);
		if (n->right != NULL) q.push(n->right);
	}
	std::cout << std::endl;
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
	root = Insert(root, 10);
	Insert(root, 10);
	Insert(root, 20);
	Insert(root, 8);
	Insert(root, 9);
	Insert(root, 15);
	Insert(root, 21);

	level_order_traversal(root);

	
}