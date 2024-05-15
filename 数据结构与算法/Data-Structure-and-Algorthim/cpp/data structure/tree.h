#include<iostream>

template<typename T>
class Tree {
private:
	class Node {
		T data;
		Node* left;
		Node* right;

		Node(T newdata) {
			data = newdata;
			left = nullptr;
			right = nullptr;
		}
	};
	Node* root;
	
	void preorder(Node* curr) {
		if (curr == nullptr)return;
		std::cout << curr->data;
		preorder(curr->left);
		preorder(curr->right);
	}
	void inorder(Node* curr) {
		if (curr == nullptr)return;
		std::cout << curr->data;
		inorder(curr->left);
		inorder(curr->right);
	}
	void postorder(Node* curr) {
		if (curr == nullptr)return;
		std::cout << curr->data;
		postorder(curr->left);
		postorder(curr->right);
	}
public:
	void inorderprint() {
		inorder(root);
	}
	void preorderprint() {
		preorder(root);
	}
	void postorderprint() {
		postorder(root);
	}

};
