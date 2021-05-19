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
Node* lca(Node *root,int n1,int n2){
    if(root==NULL) return NULL;
    if(root->data==n1 or root->data==n2) return root;
    Node *leftlca=lca(root->left,n1,n2);
    Node *rightlca=lca(root->right,n1,n2);
    if(leftlca and rightlca) return root;
    if(leftlca) return leftlca;
    return rightlca;
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
    Node *n=lca(node,4,7);
    cout<<n->data;

    return 0;
}