#include <stdio.h>
#include <stdlib.h>

struct tNode{
	int data;
	struct tNode *Lchild, *Rchild;
};

struct tNode *insert(struct tNode *curNode, int data){
	//insert
	if (curNode == NULL){
		//create new node
		struct tNode *newData = (struct tNode *) malloc(sizeof (struct tNode));
		newData->data = data;
		newData->Lchild = NULL;
		newData ->Rchild = NULL;
		return newData;
	}
	else{	//find proper position
		if (data < curNode -> data) curNode -> Lchild = insert(curNode -> Lchild, data);
		else curNode ->Rchild = insert(curNode -> Rchild, data);
	}
	return curNode;
}

void traverse(struct tNode *curNode){
//************************* You should write ***********************//
// if the current node is NULL means it goes to one of the branch end
// in-order means goes to all the node on left side until there's no other nodes,
// then print the current Node
// after printing, then goes to the right node

//hint: recursive is a good idea
//*************************** Don't forget *************************//
	if(curNode == NULL)
	{
		return;	
	}
	traverse(curNode->Lchild);
	printf("%d ",curNode->data);
	traverse(curNode->Rchild);
}

int find(struct tNode *curNode, int target){
	//************************* You should write ***********************//
	// if find the target, return the sum of data contains in its Lchild and Rchild
	// NULL is seen as 0
	// if not, return "Not in tree\n"
	//*************************** Don't forget *************************//
	if(curNode == NULL)
	{
		printf("Not in tree\n");
		return -1;
	}

	if(target < curNode->data)
	{
		return find(curNode->Lchild, target);
	}
	else if(target > curNode->data)
	{
		return find(curNode->Rchild, target);
	}
	
	int left_data, right_data;
	if(curNode->Lchild == NULL) left_data = 0;
	else left_data = (curNode->Lchild)->data;
	if(curNode->Rchild == NULL) right_data = 0; 
	else right_data = (curNode->Rchild)->data;
	return right_data + left_data;
	
}

void delete_tree(struct tNode* curNode){
	if (curNode == NULL) return;
	delete_tree(curNode->Lchild);
	delete_tree(curNode->Rchild);
	free(curNode);
}

int main(){
	int numData = 0;
	int tmpNum;
	scanf("%d", &numData);

	struct tNode *root = NULL;

	//insert every data, all data > 0
	for (int i = 0; i < numData; i++){
		scanf("%d", &tmpNum);
		root = insert(root, tmpNum);
	}

	//traverse
	traverse(root);
	puts("");

	//find
	while(scanf("%d", &tmpNum)!=EOF){
		int sum = find(root, tmpNum);
		if (sum != -1) printf("%d\n", sum);
	}

	//free memory
	delete_tree(root);
	return 0;
}
