#include <cstdio>
#include <cstdlib>
#include <iostream>

struct node{
    struct node* left;
    int data;
    struct node* right;
};

struct node* createNode(int);
void preorder(struct node *);
void inorder(struct node*);
void postorder(struct node*);

int main(){
    struct node* root=NULL;
    root=createNode(1);
    root->left=createNode(2);
    root->right=createNode(3);
    root->left->left=createNode(4);
    root->left->right=createNode(5);
    root->right->right=createNode(6);
    root->left->right->left=createNode(7);
    root->left->right->right=createNode(8);
    root->right->right->left=createNode(9);

    preorder(root);
    inorder(root);
    postorder(root);
    return 0;
}

struct node* createNode(int data){
    struct node* newNode=new node;
    newNode->left=NULL;
    newNode->data=data;
    newNode->right=NULL;
    return newNode;
}

void preorder(struct node* root){
    if(root==NULL){
        return;
    }
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void postorder(struct node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}