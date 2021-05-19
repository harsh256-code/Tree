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
int sum_at_k_level(Node *root,int k){
    if(root==NULL) return -1;
    queue<Node *>q;
    int l=0,ans=0;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* node =q.front();
        q.pop();
        //l++;
        if(node!=NULL){
            if(l==k){
                ans+=node->data;
            }
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }else if(!q.empty()){
            q.push(NULL);
            l++;
        }
    }
    return ans;
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
    int a=sum_at_k_level(node,2);
    cout<<a<<endl;
    


    return 0;
}