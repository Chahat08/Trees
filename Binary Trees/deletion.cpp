#include <iostream>
#include <queue>

struct Node
{
	int data;
	Node* left, * right;

	Node():data(0), left(NULL), right(NULL){}
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

void level_order_traversal(Node* root)
{
	if (root == NULL) return;
	std::queue<Node*> q;

	q.push(root);

	while (!q.empty())
	{
		Node* curr = q.front();
		std::cout << curr->data << " ";
		q.pop();
		if (curr->left != NULL)q.push(curr->left);
		if (curr->right != NULL)q.push(curr->right);
	}

	std::cout << std::endl;
}

Node* FindMin(Node* root)
{
	if (root->left == NULL) return root;
	return FindMin(root->left);
}
// returns the new root, which may have changed
Node* Delete(Node* root, int val)
{
	// first we have to find that node
	if (root == NULL) return root;
	else if (val < root->data) root->left = Delete(root->left, val);
	else if (val > root->data) root->right = Delete(root->right, val);
	else // root has been found, now we can delete it
	{
		// case 1: no children
		if (root->left == NULL && root->right == NULL)
		{
			delete root;
			// now root is a dangling pointer, so set it to null
			root = NULL;
		}
		// case 2: one child
		else if (root->left == NULL)
		{
			Node* temp = root;
			root = root->right;
			delete temp;
		}
		else if (root->right == NULL)
		{
			Node* temp = root;
			root = root->left;
			delete temp;
		}
		// case 3: two children
		else
		{
			Node* temp = FindMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right, temp->data);
		}
	}
	return root;
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

	level_order_traversal(root);

	root = Delete(root, 12);

	level_order_traversal(root);

}