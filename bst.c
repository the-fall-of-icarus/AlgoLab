#include <stdio.h>
#include <stdlib.h>


struct Node {
	
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* createNode(int newData){
	
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	if(newNode == NULL){
		
		printf("Memory Allocation Failed!\n");
		exit(1);
	}
	
	newNode->data = newData;
	newNode->left = NULL;
	newNode->right = NULL;
	
	return newNode;
}

struct Node* insert(struct Node* root, int data){
	
	if (root == NULL){
		return createNode(data);
	}
	
	if(data<root->data){
		
		root->left = insert(root->left, data);
	}
	else if(data>root->data){
		
		root->right = insert(root->right, data);
	}
	return root;
}

void inorder(struct Node* root){
	
	if(root!=NULL){
		
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

void preorder(struct Node* root){
	
	if(root!=NULL){
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(struct Node* root){
	
	if(root!=NULL){
		postorder(root->left);
		postorder(root->right);
		printf("%d ", root->data);
	}
}

int height(struct Node* root){
	
	if(root==NULL){
		return 0;
	}
	
	int left_h = height(root->left);
	int right_h = height(root->right);
	
	return left_h>right_h?left_h:right_h +1;
}

void max(struct Node* root){

	struct Node* p;
	p=root;

	while(p->right != NULL){
		p=p->right;
	}

	printf("The maximum number is:%d\n", p->data);
}

void min(struct Node* root){

	struct Node* p;
	p=root;

	while(p->left != NULL){
		p=p->left;
	}

	printf("The minimum number is:%d\n", p->data);
}

int main(){
	
	struct Node* root = NULL;
	
	root= insert(root,40);
	root=insert(root, 50);
	root=insert(root, 10);
	root=insert(root, 30);
	root=insert(root, 80);
	root=insert(root, 100);
	
	printf("Inorder:");
	inorder(root);
	printf("\n");
	
	printf("Preorder:");
	preorder(root);
	printf("\n");
	
	printf("Postorder:");
	postorder(root);
	printf("\n");
	
	printf("Height: %d\n", height(root));

	min(root);
	max(root);
}