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

/*To print the nodes in each level of tree-
Level Order Traversal
Algo-
1)Make a queue
	Note-FIFO flow of the queue is gonna be helpful
2)push parent node
3)Pop parent node + push child nodes
4)Push a NULL after each level
   Pop NULL and print a newline and push a NULL
5)Repeat  2,3,4
6)When queue becomes empty no need to push null*/
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
/*Level order build
First build root
Take two inputs at a time 
-1 indicates empty node
input is in left-right format
pop left element first and then insert the child nodes
then pop right element and then insert the child nodes*/
Node* levelOrderBuild(){
    int d;
    cin>>d;
    Node*root=new Node(d);
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* current=q.front();
        q.pop();
        int c1,c2;
        cin>>c1>>c2;
        if(c1!=-1){
            current->left=new Node(c1);
            q.push(current->left);
        }
        if(c2!=-1){
            current->right=new Node(c2);
            q.push(current->right);
        }
        
    }
    return root;
}
//Height of the tree
/*Height of the tree can be computed by taking max of the heights of left and right subtrees and adding 1 to it*/
int height(Node*root){
    if(root==NULL){
        return 0;
    }
    int h1=height(root->left);
    int h2=height(root->right);
    return 1+ max(h1,h2);
}
//Diameter of a Binary tree is the distance between 2 farthest nodes//
/*If diameter passes through the tree LH-1+RH-1+2=LH+RH
If diameter is in leftsubtree-say D2
If diameter passes from left subtree ,right subtree and root-say D1
If diameter passes through right subtree say-D3
Then Diameter =max(D1,D2,D3)
if root is null D=0
D1=h1+h2
D2=diameter(root->left)
D3=diameter(root->right)
*/
//Time Complexity-N^2
int diameter(Node* root){
    //base case
    if(root==NULL){
        return 0;
    }
    //recursive case
    int D1=height(root->left)+height(root->right);
    int D2=diameter(root->left);//bottom up approach
    int D3=diameter(root->right);
    return max(D1,max(D2,D3));
}
//Optimised diameter function
/*From every node return height and diameter*/
class HDPair{
    public:
    int height;
    int diameter;
};
HDPair optDiameter(Node* root){
    HDPair p;
    if(root==NULL){
        p.height=p.diameter=0;
        return p;
    }
    //otherwise
    HDPair left= optDiameter(root->left);
    HDPair right=optDiameter(root->right);
    p.height=max(left.height,right.height)+1;
    int D1=left.height+right.height;
    int D2=left.diameter;
    int D3=right.diameter;
    p.diameter=max(D1,max(D2,D3));
    return p;
}
int main(){
    cout<<"\nlevelOrderBuild I/P\n";
 Node*root=levelOrderBuild();
 cout<<"\nlevelOrderBuild O/P\n";
 levelOrder(root);
 cout<<"\nHeight of the tree is "<<height(root);
 cout<<"\nDiameter of the tree is "<<diameter(root);
 cout<<"\nOptmised diameter of the tree is "<<optDiameter(root).diameter;
}
//Input-1 2 3 4 5 -1 6 -1 -1 7 -1 -1 -1 -1 -1
/*1 
2 3
4 5 6
7*/