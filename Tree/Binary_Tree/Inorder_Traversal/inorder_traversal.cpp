#include <bits/stdc++.h>
using namespace std;


struct Node {
	int data;
	struct Node *left, *right;
	Node(int data)
	{
		this->data = data;
		left = right = NULL;
	}
};

void Inorder(struct Node* node)
{
	if (node == NULL)
		return;


	Inorder(node->left);

	
	cout << node->data << " ";


	Inorder(node->right);
}




int main()
{
	struct Node* root = new Node(6);
	root->left = new Node(8);
	root->right = new Node(9);
	root->left->left = new Node(4);
	root->left->right = new Node(5);

	cout << "\nInorder traversal of binary tree is \n";
	Inorder(root);

  return 0;
}

