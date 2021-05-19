#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};
void inorder(Node *root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(Node *root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    inorder(root->left);
    inorder(root->right);
}
void postorder(Node *root){
    if(root==NULL) return;
    inorder(root->left);
    inorder(root->right);
    cout<<root->data<<" ";
}
int main(){
    Node *node=new Node(1);
    node->left=new Node(2);
    node->right=new Node(3);
    node->left->left=new Node(4);
    node->left->right=new Node(5);
    node->right->left=new Node(6);
    node->right->right=new Node(7);
    inorder(node);
    cout<<"\n";
    preorder(node);
    cout<<"\n";
    postorder(node);
    


    return 0;
}