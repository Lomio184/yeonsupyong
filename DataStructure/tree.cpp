#include <stdio.h>
#include <iostream>

struct Node
{
    int data ;
    Node* left;
    Node* right;

    Node( int value ):data(value), left(nullptr), right(nullptr){}
} ;

class BinaryTree
{
private:
    Node* root;

    void inorderTraversal( Node* node )
    {
        if ( node == nullptr )
        {
            return ;
        }

        inorderTraversal( node->left );
        printf("%d\t", node->data) ;
        inorderTraversal( node->right ) ;
    }

    void preorderTraversal(Node* node) {
        if (node == nullptr) return;

        printf("%d\t", node->data) ;
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }

    void postorderTraversal(Node* node) {
        if (node == nullptr) return;

        postorderTraversal(node->left);
        postorderTraversal(node->right);
        printf("%d\t", node->data) ;
    }

    Node* findMin(Node* node) {
        while (node && node->left != nullptr)
            node = node->left;
        return node;
    }

    Node* insert( Node* node, int value )
    {
        if ( node == nullptr )
        {
            return new Node( value );
        }

        if ( value < node->data )
        {
            node->left = insert( node->left, value );
        }
        else
        {
            node->right = insert( node->right, value ) ;
        }

        return node ;
    }

    Node* remove( Node* node, int value )
    {
        if ( node == nullptr )
        {
            return node ;
        }

        if ( value < node->data )
        {
            node->left = remove( node->left, value );
        }
        else if ( value > node->data )
        {
            node->right = remove( node->right, value );
        }
        else
        {
            if ( node->left == nullptr )
            {
                Node* temp = node->right ;
                delete node ;
                return temp ;
            }
            else if ( node->right == nullptr )
            {
                Node* temp = node->left ;
                delete node ;
                return temp ;
            }

            Node *temp = findMin( node->right );
            node->data = temp->data ;
            node->right = remove( node->right, temp->data ) ;
        }

        return node ;
    }

public:
    BinaryTree() : root( nullptr ){}

    void Insert( int value )
    {
        root = insert( root, value );
    }

    void InorderTraversal()
    {
        inorderTraversal( root );
        printf("\n");
    }

    void Remove(int value) {
        root = remove(root, value);
    }

    void PreorderTraversal() {
        preorderTraversal(root);
        std::cout << std::endl;
    }

    void PostorderTraversal() {
        postorderTraversal(root);
        std::cout << std::endl;
    }
};

int main() {
    BinaryTree tree;

    tree.Insert(50);
    tree.Insert(30);
    tree.Insert(20);
    tree.Insert(40);
    tree.Insert(70);
    tree.Insert(60);
    tree.Insert(80);

    tree.InorderTraversal();

    tree.Remove(20);
    std::cout << "After removing 20, Inorder traversal: ";
    tree.InorderTraversal();

    return 0;
}