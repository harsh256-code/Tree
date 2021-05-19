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
int searche(int in[],int s,int e,int curr){
    for(int i=s;i<=e;i++){
        if(in[i]==curr) return i;
    }
    return -1;
}
Node* from_postorder_and_inorder(int post[],int in[],int s,int e,int &idx){
    if(s>e) return NULL;
    int curr=post[idx];
    idx--;
    Node* node=new Node(curr);
    if(s==e) return node;
    int pos=searche(in,s,e,curr);
    node->right=from_postorder_and_inorder(post,in,pos+1,e,idx);
    node->left=from_postorder_and_inorder(post,in,s,pos-1,idx);
    
    return node;


}
void inorderT(Node *root){
    if(root==NULL) return;
    inorderT(root->left);
    cout<<root->data<<" ";
    inorderT(root->right);
}
int main(){
    //1 4 2 5 6 3 7
    //4 2 5 6 3 7 1
    //4 2 5 6 3 7 1
    int postorder[]={4,2,5,6,3,7,1};
    int inorder[]={4,2,5,1,6,3,7};
    int idx=6;
    Node *root=from_postorder_and_inorder(postorder,inorder,0,6,idx);
    inorderT(root);

    return 0;
}