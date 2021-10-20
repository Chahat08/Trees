#include <iostream>
#include <vector>

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

int bin_search(int x, std::vector<Node*>& v, int l, int r)
{
	if (l > r) return -1;

	int m = (l + r) / 2;
	if (x == v[m]->data) return m;
	else if (x < v[m]->data) return bin_search(x, v, l, m-1);
	else return bin_search(x, v, m+1, r);
}
void inorder_traversal(Node* root, std::vector<Node*>& v)
{
	// runtime: O(n)
	if (root == NULL) return;
	inorder_traversal(root->left, v);
	v.push_back(root);
	inorder_traversal(root->right, v);
}
Node* inorder_successor_naive(Node* root, int x)
{
	// runtime: O(n)
	std::vector<Node*> v;
	inorder_traversal(root, v);
	// v is now sorted, a simple binary_search will give us the index
	int i = bin_search(x, v, 0, v.size() - 1); // O(log n)
	return v[i + 1];
}

Node* FindNode(Node* root, int x)
{
	if (root->data == x) return root;
	else if (x <= root->data) return FindNode(root->left, x);
	else return FindNode(root->right, x);
}
Node* FindMin(Node* root)
{
	if (!root->left) return root;
	return FindMin(root->left);
}
Node* inorder_successor(Node* root, int x)
{
	// O(h)

	Node* n = FindNode(root, x);

	if (n->right)
	{
		// return smallest node in right subtree
		return FindMin(n->right);
	}
	else
	{
		// return nearest ancestor to whose left this node lies
		// or return null for the largest node in tree
		Node* successor = NULL;
		Node* ancestor = root;

		while (ancestor != n) // start from the root, till the current node
		{
			if (x < ancestor->data)
			{
				successor = ancestor;
				ancestor = ancestor->left;
			}
			else
				ancestor = ancestor->right;
		}

		return successor;
	}
}

Node* inorder_predecessor_naive(Node* root, int x)
{
	std::vector<Node*> v;
	inorder_traversal(root, v);
	int i = bin_search(x, v, 0, v.size() - 1);
	if (i == 0) return NULL;
	return v[i - 1];
}

Node* FindMax(Node* root)
{
	if (!root->right) return root;
	return FindMax(root->right);
}
Node* inorder_predecessor(Node* root, int x)
{
	Node* n = FindNode(root, x);

	// if left subtree exists, then the inorder pred
	// is the max node in the left subtree
	if (n->left) return FindMax(n->left);

	else
	{
		// the nearest ancestor to whom the curr node lies rightwards (wrt it)
		Node* predecessor = NULL;
		Node* ancestor = root;

		while (ancestor != n)
		{
			if (x > ancestor->data)
			{
				predecessor = ancestor;
				ancestor = ancestor->right;
			}
			else ancestor = ancestor->left;
		}
		return predecessor;
	}
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

	std::cout << 12<< ": " << inorder_successor(root, 12)->data << " " << inorder_successor_naive(root, 12)->data << std::endl;
	std::cout << 3 <<": " << inorder_successor(root, 3)->data << " " << inorder_successor_naive(root, 3)->data << std::endl;
	std::cout << 13<<": "  << inorder_successor(root, 13)->data << " " << inorder_successor_naive(root, 13)->data << std::endl;
	std::cout << 5<< ": " << inorder_successor(root, 5)->data << " " << inorder_successor_naive(root, 5)->data << std::endl;
	
	std::cout << std::endl;

	std::cout << 12<< ": " << inorder_predecessor(root, 12)->data << " " << inorder_predecessor_naive(root, 12)->data << std::endl;
	std::cout << 3<< ": " << inorder_predecessor(root, 3)->data << " " << inorder_predecessor_naive(root, 3)->data << std::endl;
	std::cout << 13<< ": " << inorder_predecessor(root, 13)->data << " " << inorder_predecessor_naive(root, 13)->data << std::endl;
	std::cout << 5<< ": " << inorder_predecessor(root, 15)->data << " " << inorder_predecessor_naive(root, 5)->data << std::endl;

	return 0;

}