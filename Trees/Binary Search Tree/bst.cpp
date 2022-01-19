#include<iostream>
#include<vector>
#include<queue>
using namespace std;
//all subtrees of a root node should be a bst
//inorder traversal of BST will always be sorted
 //Time complexity O(h)
 //ln(N)<=H<=N
 //recursive 
 class Node{
     public:
     int key;
     Node *left;
     Node*right;
     Node(int key){
         this->key =key;
        left=right=NULL;
     }
 };
 Node* insert(Node*root,int key){
     if(root==0){
         return new Node (key);
     }
     //recursion
     if(key<root->key){
         root->left=insert(root->left,key);

     }
     else{
         root->right=insert(root->right,key);
     }
     return root;
 }
 void printInOrder(Node*root){
     if(root==NULL)
        return;
    printInOrder(root->left);
    cout<<root->key<<" ";
    printInOrder(root->right);

 }
 //root to leaf treaversaL
 bool search(Node*root,int key){
     if(root==NULL)
        return false;
    if(root->key==key)
    return true;
    if(key<root->key)
    return search(root->left,key);
    return search(root->right,key);
 }
 int main(){
     Node* root=NULL;
     int arr[]={8,3,10,1,6,14,4,7,13};
     for(int x: arr){
         root=insert(root,x);
     }
     
     printInOrder(root);
     cout<<endl;
     int key;
     cout<<"Enter the key that you wish to search: ";
     cin>>key;
     if(search(root,key)==1)
     cout<<"Found";
     else
     cout<<"Not Found";
 }