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
Node* from_preorder_and_inorder(int pre[],int in[],int s,int e,int &idx){
    if(s>e) return NULL;
    int curr=pre[idx];
    idx++;
    Node* node=new Node(curr);
    if(s==e) return node;
    int pos=searche(in,s,e,curr);
    node->left=from_preorder_and_inorder(pre,in,s,pos-1,idx);
    node->right=from_preorder_and_inorder(pre,in,pos+1,e,idx);
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
    int preorder[]={1,4,2,5,6,3,7};
    int inorder[]={4,2,5,1,6,3,7};
    int idx=0;
    Node *root=from_preorder_and_inorder(preorder,inorder,0,6,idx);
    inorderT(root);

    return 0;
}