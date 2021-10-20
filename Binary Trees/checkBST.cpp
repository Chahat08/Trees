#include <iostream>
#include <vector>

class Node
{
public:
	int data;
	Node* left, * right;
};

// AIM: to check if the given binary is a binary search tree or not.


// APPROACH 1: Recursively check if given value is
// lesser or greater than all values in its subtrees

// Time complexity: O(N^2), will check the same nodes multiple times
bool isBSTLesser(Node* root, int val)
{
	if (root == NULL) return true;
	if (root->data <= val && isBSTLesser(root->left, val) && isBSTLesser(root->right, val))
		return true;
	else return false;
}
bool isBSTGreater(Node* root, int val)
{
	if (root == NULL) return true;
	if (root->data > val && isBSTLesser(root->left, val) && isBSTLesser(root->right, val))
		return true;
	else return false;
}
bool isBST1(Node* root)
{
	if (root == NULL) return true;
	if (isBSTLesser(root->left, root->data) && isBSTGreater(root->right, root->data) &&
		isBST1(root->left) && isBST1(root->right))
		return true;
	else return false;
}

// APPROACH 2: The value in a node is bound by values in the previous node
// so we stop with the calls to the isBSTGreater and isBSTLesser
// and ensure by ourselves if the current node's data falls in this range.

// Runtime: O(N)
bool isBST2(Node* root, int min_val = INT_MIN, int max_val = INT_MAX)
{
	if (root == NULL) return true;
	
	if (isBST2(root->data >= min_val && root->data < max_val)
		&& isBST2(root->left, min_val, root->data)
		&& isBST2(root->right, root->data, max_val)
		) return true;
	else return false;
}

// APPROACH 3: Inorder traversal of a BST gives a sorted list

// Runtime: O(n) for Inorder traversal and one pass through the list
// Space complexity: O(n)
void isBSTUtil1(Node* root, std::vector<int>& v)
{
	if (root == NULL) return;

	isBSTUtil(root->left);
	v.push_back(root->data);
	isBSTUtil(root->right);
}
bool isBST_(Node* root)
{
	std::vector<int> v;
	isBSTUtil(root, v);
	bool ret = true;
	for (int i = 1; i < v.size(); ++i)
		if (v[i] < v[i - 1]) { ret = false; break; }
	return false;
}

// APPROACH 3: Inorder traversal of a BST gives a sorted list
// but instead of storing as list we only keep track of current and prev values.

// Runtime: O(n) for Inorder traversal and one pass through the list
// Space complexity: O(n)
void isBST(Node* root, int val = INT_MIN)
{
	if (root == NULL) return true;

	isBSTUtil(root->left, root->data);
	if (root->data < val) return false;
	else return true;
	isBSTUtil(root->right, root->data);
}