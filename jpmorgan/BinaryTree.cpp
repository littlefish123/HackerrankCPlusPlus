#include <iostream>

using namespace std;

class Node {
public:
	int key;
	Node* left;
	Node* right;

	Node(int item) {
		key = item;
		left = right = nullptr;
	}
};

class BinaryTree {
public:
	Node* root;

	BinaryTree() {
		root = nullptr;
	}

	Node* insert(Node* node, int key) {
		if (node == nullptr) {
			return new Node(key);
		}

		if (key < node->key)
			node->left = insert(node->left, key);
		else if (key > node->key)
			node->right = insert(node->right, key);

		return node;
	}

	void add(int key) {
		root = insert(root, key);
	}

	void inorder(Node* node) {
		if (node == nullptr) {
			return;
		}
		inorder(node->left);
		cout << node->key << std::endl;
		inorder(node->right);
	}
};

int main() {
	BinaryTree* tree = new BinaryTree();
	tree->add(50);
	tree->add(50);
	tree->add(30);
	tree->add(70);
	tree->add(20);
	tree->add(40);
	tree->add(60);
	tree->add(80);

	std::cout << "Inorder traversal of the tree:" << std::endl;
	tree->inorder(tree->root);

	delete tree;

}