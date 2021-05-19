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
int finddis(Node *root,int k,int dis){
    if(root==NULL) return -1;
    if(root->data==k) return dis;
    int left=finddis(root->left,k,dis+1);
    if(left!=-1) return left;
    return finddis(root->right,k,dis+1) ;

}
int shortest_distance(Node *root,int n1,int n2){ //return Shortest distance b/w tow nodes
    Node *Lca=lca(root,n1,n2);
    int d1=finddis(Lca,n1,0);
    int d2=finddis(Lca,n2,0);
    return d1+d2;
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
    cout<<shortest_distance(node,2,7);

    return 0;
}