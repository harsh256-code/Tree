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
int diameter(Node *root,int *h){
    if(root==NULL){
        *h=0;
        return 0;
    }
    int lh=0,rh=0;
    int ld=diameter(root->left,&lh);
    int rd=diameter(root->right,&rh);
    int cd=lh+rh+1;
    *h=max(lh,rh)+1;
    return max(cd,max(ld,rd));

}
int height(Node *root){
    if(root==NULL) return 0;
    int lh=height(root->left);
    int rh=height(root->right);
    return max(lh,rh)+1;

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
    int h=0;
    int a=diameter(node,&h);
    cout<<a<<endl;
    


    return 0;
}