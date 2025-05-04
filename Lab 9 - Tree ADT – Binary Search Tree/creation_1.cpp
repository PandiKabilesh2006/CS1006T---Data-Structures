#include <cstdio>
#include <cstdlib>
#include <iostream>

struct node{
    struct node* left;
    int data;
    struct node* right;
};
int main(){
    char preArr[]={'A','B','D','E','C'};
    char inArr[]={'D','B','E','A','C'};
    int length=sizeof(inArr)/sizeof(inArr[0]);
    struct node* root=constructBT(inArr,preArr,length-1);

}

struct node* constructBT(char inArr[],char preArr[],int inEnd){
    static int preIndex=0;
    struct node* temp=createNode(preArr[preIndex]);
    int inIndex=searchIn(inArr,temp->data,inEnd);
    preIndex++;
    temp->left=constructBT(inArr,preArr,inIndex-1);
    temp->right=constructBT(inArr,preArr,inEnd);
}

struct node* createNode(char data){
    struct node *ptr=new node;
    ptr->left=NULL;
    ptr->data=data;
    ptr->right=NULL;
    return ptr;
}

int searchIn(char inArr[],char data,int inEnd){
    int i;
    for(i=0;i<=inEnd;i++){
        if(inArr[i]==data){
            return i;        
        }

    }
}