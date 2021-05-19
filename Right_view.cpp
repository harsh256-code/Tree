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
void right_view(Node *root){
    if(!root) return;
    //cout<<root->data<<" ";
    queue<Node *>q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        for(int i=1;i<=n;i++){
            Node *node=q.front();
            q.pop();
            if(i==n){
                cout<<node->data<<" ";
            }
            if(node->left) q.push(node->left);
            if(node->right)q.push(node->right);
        }
    }
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
    right_view(node);


    return 0;
}