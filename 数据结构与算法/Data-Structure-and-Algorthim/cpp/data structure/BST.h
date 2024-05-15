#include<iostream>

using namespace std;

// Purpose: Implementation of BST class
template<typename T>
class BST {
private:
    // Purpose: Node class for BST
    class Node {
    public:
        T data;
        Node* left;
        Node* right;
        // Constructor
        Node(T newdata) : data(newdata), left(nullptr), right(nullptr) {}
    };

    Node* root;
    //插入节点
    Node* insert(Node* node, T data) {
        //如果节点为空，返回新节点
        if (node == nullptr) {
            return new Node(data);
        }//如果节点不为空，判断要插入的值与节点的值的大小
        if (data < node->data) {
            node->left = insert(node->left, data);
        }//如果要插入的值小于节点的值，递归左子树
        else if (data > node->data) {
            node->right = insert(node->right, data);
        }//如果要插入的值大于节点的值，递归右子树
        return node;
    }
    //查找节点
    bool search(Node* node, T data) {
        //如果节点为空，返回false
        if (node == nullptr) {
            return false;
        }//如果节点不为空，判断要查找的值与节点的值的大小
		else if (data < node->data) {
            return search(node->left, data);
        }//如果要查找的值大于节点的值，递归右子树
        else if (data > node->data) {
            return search(node->right, data);
        }
        //如果要查找的值等于节点的值，返回true
        return true;
    }
    //找到右子树中最小的节点
    Node* findMinNode(Node* node) {
        //如果节点为空，返回空
        Node* current = node;
        if (current == nullptr) return current;

        //如果节点不为空，一直向左找，直到找到最小的节点
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }
    //删除节点
    Node* remove(Node* root, T data) {
        //找到要删除的节点
        if (root == nullptr) return root;
        //如果要删除的节点小于根节点，递归左子树
        if (data < root->data) {
            root->left = remove(root->left, data);
        }//如果要删除的节点大于根节点，递归右子树
        else if (data > root->data) {
            root->right = remove(root->right, data);
        }//如果要删除的节点等于根节点
        else {
            //如果要删除的节点没有左子树
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            }//如果要删除的节点没有右子树
            else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            //如果要删除的节点有左右子树
            //找到右子树中最小的节点
            //将该节点的值赋值给要删除的节点
            //删除该节点
            
            Node* temp = findMinNode(root->right);
            root->data = temp->data;
            root->right = remove(root->right, temp->data);
        }
        //返回根节点
        return root;
    }
    //删除树
    void deleteTree(Node* node) {
        if (node) {
            //递归删除左右子树
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }
    }
    //打印树
    void printTree(Node*root) {
        if (!root)return;
        cout << root->data << "\t";
        printTree(root->left);
        printTree(root->right);
    }
public:
    // Constructor
    BST() : root(nullptr) {}
    // Destructor
    ~BST() {
        deleteTree(root);
    }
    //在外部调用时，调用私有成员函数
    void insert(T data) {
        //如果根节点为空，直接插入
        root = insert(root, data);
    }
    //在外部调用时，调用私有成员函数
    bool search(T data) {
        //如果根节点为空，返回false
        return search(root, data);
    }
    //在外部调用时，调用私有成员函数
    void remove(T data) {
        //如果根节点为空，直接返回
        root = remove(root, data);
    }
    //在外部调用时，调用私有成员函数
    void print() {
        printTree(root);
        std::cout << endl;
    }
};
