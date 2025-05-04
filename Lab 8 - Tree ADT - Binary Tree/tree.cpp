#include <iostream>
#include <cmath> 
#include <queue>
using namespace std;

//This program is to implement Tree ADT using linked list
class Tree
{
private:
    struct node
    {
        char data;
        struct node *left;
        struct node *right;
    }*root;

public:
    Tree();
    node *getRoot();
    void insert(char);
    void preorder(node *root);
    void inorder(node *root);
    void postorder(node *root);
    int search(char);
};

int main()
{
    int choice, depth;
    char val;
    Tree tree;
    do
    {
        cout << "\n\nMENU :\n 1. Insert\n 2. Preorder\n 3. Inorder\n 4. Postorder\n 5. Search\n 6. Exit" << endl;
        cout << "Enter choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value to insert : ";
            cin >> val;
            tree.insert(val);
            cout << "Insertion Successful." << endl;
            break;

        case 2:
            tree.preorder(tree.getRoot());
            break;

        case 3:
            tree.inorder(tree.getRoot());
            break;

        case 4:
            tree.postorder(tree.getRoot());
            break;

        case 5:
            cout << "Enter element to search for : ";
            cin >> val;
            depth = tree.search(val);
            if (depth != -1)
            {
                cout << "Element found at depth " << depth << endl;
            }
            else
            {
                cout << "Element not found." << endl;
            }
            break;

        case 6:
            cout << "Exiting program." << endl;
            break;

        default:
            cout << "Invalid choice. Enter again." << endl;
            break;
        }
    } while (choice != 6);
}

// Constructor function to initialize root to NULL
Tree::Tree()
{
    root = NULL;
}

// Getter function to get root
Tree::node *Tree::getRoot()
{
    return root;
}

// Function to traverse by level order and insert an element at the first free spot
// Time complexity = O(n)
void Tree::insert(char val)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
    if (root == NULL)
    {
        root = newnode;
        return;
    }
    queue<node *> q;
    q.push(root);
    while (true)
    {
        node *temp = q.front();
        q.pop();
        if (temp->left)
        {
            q.push(temp->left);
        }
        else
        {
            temp->left = newnode;
            return;
        }
        if (temp->right)
        {
            q.push(temp->right);
        }
        else
        {
            temp->right = newnode;
            return;
        }
    }
}

// Function to display the tree in preorder format
// Time complexity = O(n)
void Tree::preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << "  ";
    preorder(root->left);
    preorder(root->right);
}

// Function to display the tree in inorder format
// Time complexity = O(n)
void Tree::inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << "  ";
    inorder(root->right);
}

// Function to display the tree in postorder format
// Time complexity = O(n)
void Tree::postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << "  ";
}

// Function to search for an element by level order traversal
// Time complexity = O(n)
int Tree::search(char val)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == val)
    {
        return 0;
    }
    queue<node *> q;
    q.push(root);
    int depth = 0;
    while (!q.empty())
    {
        depth++;
        node *temp = q.front();
        q.pop();
        if (temp->data == val)
        {
            return log2(depth);
        }
        if (temp->left)
        {
            q.push(temp->left);
        }
        if (temp->right)
        {
            q.push(temp->right);
        }
    }
    return -1;
}