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
bool height_balanced_BT(Node *root,int *h){
    if(root==NULL) return true;
    int lh=0,rh=0;
    if(height_balanced_BT(root->left,&lh)==false) return false;
    if(height_balanced_BT(root->right,&rh)==false) return false;
    *h=max(lh,rh)+1;
    if(abs(lh-rh)<=1) return true;
    else return false;

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
    //node->right=new Node(3);
    node->left->left=new Node(4);
    node->left->right=new Node(5);
    node->right->left=new Node(6);
    node->right->right=new Node(7);
    int h=0;
    if(height_balanced_BT(node,&h)) cout<<"Balanced"<<"\n";
    else cout<<"UnBalanced"<<"\n";
    


    return 0;
}