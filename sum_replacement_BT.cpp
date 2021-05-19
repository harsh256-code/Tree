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
int sumReplacement(Node *root){
    if(root==NULL) return 0;
    int val=root->data;
    root->data=sumReplacement(root->left)+sumReplacement(root->right);
    return root->data+val;
}
void inorder(Node *root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
/*
        1
      /   \
     2     3
    / \   / \
   4   5 6   7
*/
int main(){
    Node *node=new Node(1);
    node->left=new Node(2);
    node->right=new Node(3);
    node->left->left=new Node(4);
    node->left->right=new Node(5);
    node->right->left=new Node(6);
    node->right->right=new Node(7);
    inorder(node);
    cout<<endl;
    sumReplacement(node);
    inorder(node);
    


    return 0;
}