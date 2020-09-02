#include<bits/stdc++.h>
#include<queue>
#define lli long long int 
using namespace std;
struct bstNode {
	int data;
	bstNode* left;
	bstNode* right;
};
bstNode* getnewNode(int data){
	bstNode* newNode=new bstNode();//memory allocation in cpp
	newNode->data=data;
	newNode->left=newNode->right=NULL;
	return newNode;
}

bstNode* Insert(bstNode* root,int data){
	if(root==NULL){
		root=getnewNode(data);
	}
	else if(root->data>=data){
		
		root->left=Insert(root->left,data);
	}
	else if(root->data<data){
		root->right=Insert(root->right,data);
	}
	return root;
}

bool Search(bstNode*root,int x){
	if(root==NULL){
		return false;
	}
	else if(root->data==x) return true;
	else if(root->data>=x) return Search(root->left,x);
	else return Search(root->right,x);
}

bstNode* Findmin(bstNode* root){
	while(root->left !=NULL){
		root=root->left;
	}
	return root;
}

bstNode* Findmax(bstNode * root){
	while(root->right!=NULL){
		root=root->right;
	}
	return root;
}

int Findminvalue(bstNode* root){
	if(root==NULL){
		return -1;
	}
	while(root->left!=NULL){
		root=root->left;
	}
	return root->data;
}
int Findmaxvalue(bstNode* root){
	if(root==NULL){
		return -1;
	}
	while(root->right!=NULL){
		root=root->right;
	}
	return root->data;
}

//finding height of the tree using recursive method  : O(n)
int heightTree(bstNode* root){
	if(root==NULL){
		return -1;
	}
	int leftTreeH=heightTree(root->left);
	int rightTreeH=heightTree(root->right);
	return max(leftTreeH,rightTreeH) +1 ;
}

// iterative methond to find height
int heightTree_Iterative(bstNode* root){
	if(root==NULL){
		return 0;
	}
	queue<bstNode*>q;
	q.push(root);
	int height=0;
	while(1){
		int nodecount=q.size();
		if(nodecount==0){
			return height;
		}
		height++;
		while(nodecount>0){
			bstNode* node=q.front();
			q.pop();
			if(node->left!=NULL){
				q.push(node->left);
			}
			if(node->right!=NULL){
				q.push(node->right);
			}
			nodecount--;
		}
	}
} 

bstNode* Delete( bstNode* root,int data){
	if(root==NULL){
		return root;
	}
	else if(root->data > data) { root->right = Delete(  root->right,data);}
	else if(root->data < data) { root->left = Delete(root->left,data);} 
	else{  //and yess we found that root,now lets check if it having child & how many and which one
	    // case I : no childs
	    if(root->left==NULL && root->right==NULL ){
	    	delete root;
	    	root= NULL;
	    }
	    // case II : either right child or left child is available 
	    // case II_1: right child only
	    else if(root->left==NULL){
	    	struct bstNode* temp= root;
	    	root=root->right;
	    	delete temp;
	    }
	    //  case II_2: left child only
	    else if(root->right==NULL){
	    	struct bstNode* temp=root;
	    	root=root->left;
	    	delete temp;
	    }
	    // case III : if it has both childs
	    else{
	    	// take min from right sub-tree 
	    	struct bstNode* temp= Findmin(root->right);
	    	root->data = temp->data;
	    	root->right = Delete(root->right ,temp->data);
	    }
	}
	return root;
}
//  bfs 
void bfs(bstNode* root){
	if(root==NULL){
	    return ;
	}
	queue<bstNode*>q;
	q.push(root);
	while(!q.empty()){
		bstNode* temp=q.front();
		if(temp->left!=NULL){
			q.push(temp->left);
		}
		if(temp->right!=NULL){
			q.push(temp->right);
		}
		q.pop();
	}
}
// dfs  
 //preorder r-L-R
void PreorderTraversal(bstNode* root){
	if(root==NULL){
	   return;
	}
	cout<<root->data<<" ";
	PreorderTraversal(root->left);
	PreorderTraversal(root->right);
} 
 //postorder L-R-r
void PostorderTraversal(bstNode* root){
	if(root==NULL){
	   return;
	}
	PostorderTraversal(root->left);
	PostorderTraversal(root->right);
	cout<<root->data<<" ";
} 
//Inorder L-r-R
void InorderTraversal(bstNode* root){
	if(root==NULL){
	   return;
	}
	InorderTraversal(root->left);
	cout<<root->data<<" ";
	InorderTraversal(root->right);
}  
 // check if a TREE  is binary or not
 //supporter functions islesser and isgreater
 bool islesser(bstNode* root, int value){
 	if(root==NULL){
 		return true;
 	}
 	if(root->data <=value && islesser(root->left,value) && islesser(root->right,value)){
 		return true;
 	}
 	else{
 		return false;
 	}
 }
  //isgreater
bool isgreater(bstNode* root, int value){
 	if(root==NULL){
 		return true;
 	}
 	if(root->data <=value && isgreater(root->left,value) && isgreater(root->right,value)){
 		return true;
 	}
 	else{
 		return false;
 	}
 }
 // main function to check 
 bool isBST(bstNode* root){
 	if (root==NULL){
 		return true;
 	}
 	if(islesser(root->left,root->data) && isgreater(root->right,root->data) && isBST(root->right) && isBST(root->left)){
 		return true;
 	}
 	else{
 		return false;
 	}
 }
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //creating an empty tree
    bstNode* root=NULL;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
    	int data;
    	cin>>data;
    root=Insert(root,data);
    }
     InorderTraversal(root);
    cout<<"\n";
   PreorderTraversal(root);
    cout<<"\n";
    PostorderTraversal(root);
	return 0;
}
