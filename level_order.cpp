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
void levelorder(Node *root){
    queue<Node *>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* node =q.front();
        q.pop();
        if(node!=NULL){
            cout<<node->data<<" ";
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }else if(!q.empty()){
            q.push(NULL);
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
    levelorder(node);
    


    return 0;
}