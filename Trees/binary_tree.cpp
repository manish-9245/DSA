#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Node{
public:
int data;
Node* left;
Node* right;
Node(int d){
data=d;
left=right=NULL;
}
};

Node*buildTree(){
    int d;
    cin>>d;
    if(d==-1){
        return NULL;
    }
    Node*n= new Node(d);
    n->left=buildTree();
    n->right=buildTree();
}

//I/p- 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
//Preorder O/P
//1 2 4 5 7 3 6
// Inorder O/P
//4 2 7 5 1 3 6
//Postorder O/P
//4 7 5 2 6 3 1

//PreOrder Build of the Tree- Root,Left,Right
void printPreorder(Node*root){
if(root==NULL){
    return;
}
cout<<root->data<<" ";
printPreorder(root->left);
printPreorder(root->right);
}
//InOrder Build of the Tree- Left ,Root, Right

void printInorder(Node *root){
if(root==NULL){
    return;
}
printInorder(root->left);
cout<<root->data<<" ";
printInorder(root->right);
}
//Post Order traversal of Binary Tree- Left,Right,Root
//Bottom Up Approach
void printPostorder(Node *root){
if(root==NULL){
    return;
}
printPostorder(root->left);
printPostorder(root->right);
cout<<root->data<<" ";
}
void levelOrder(Node *root){
    queue <Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp=q.front();
        if(temp==NULL){
           cout<<endl;
           q.pop();
           //Insert a new null
           if(!q.empty()){
            q.push(NULL);
           }

        }
        else{
            q.pop();
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
    
}
int main(){
//The main origin is called the root node
//2 nodes coming out of the same node are siblings to each other
//Any node with 0 child nodes is called a leaf node
//Ancestors are all the previous root nodes
//Height of the tree is the number of levels
//Depth of a tree is the Level it belongs to
//Each node has at most 2 children
//Mostly recursive
 Node*root=buildTree();
 cout<<"\nPreorder O/P\n";
 printPreorder(root);
 cout<<"\nInorder O/P\n";
 printInorder(root);
 cout<<"\nPostorder O/P\n";
 printPostorder(root);
 cout<<"\nlevelOrder O/P\n";
 levelOrder(root);
return 0;
}
