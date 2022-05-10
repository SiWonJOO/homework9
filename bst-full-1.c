/*
 * Binary Search Tree #1
 *
 * Data Structures
 *
 * School of Computer Science
 * at Chungbuk National University
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int key;
	struct node *left;
	struct node *right;
} Node;

int initializeBST(Node** h);

/* functions that you have to implement */
void inorderTraversal(Node* ptr);	  /* recursive inorder traversal */
void preorderTraversal(Node* ptr);    /* recursive preorder traversal */
void postorderTraversal(Node* ptr);	  /* recursive postorder traversal */
int insert(Node* head, int key);  /* insert a node to the tree */
int deleteLeafNode(Node* head, int key);  /* delete the leaf node for the key */
Node* searchRecursive(Node* ptr, int key);  /* search the node for the key */
Node* searchIterative(Node* head, int key);  /* search the node for the key */
int freeBST(Node* head); /* free all memories allocated to the tree */

/* you may add your own defined functions if necessary */


int main()
{
	char command;
	int key;
	Node* head = NULL;
	Node* ptr = NULL;	/* temp */

 printf("[----- [SIWON JOO] [2018038045] -----]");

	do{
		printf("\n\n");
		printf("----------------------------------------------------------------\n");
		printf("                   Binary Search Tree #1                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize BST       = z                                       \n");
		printf(" Insert Node          = n      Delete Leaf Node             = d \n");
		printf(" Inorder Traversal    = i      Search Node Recursively      = s \n");
		printf(" Preorder Traversal   = p      Search Node Iteratively      = f\n");
		printf(" Postorder Traversal  = t      Quit                         = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'z': case 'Z':
			initializeBST(&head);
			break;
		case 'q': case 'Q':
			freeBST(head);
			break;
		case 'n': case 'N':
			printf("Your Key = ");
			scanf("%d", &key);
			insert(head, key);
			break;
		case 'd': case 'D':
			printf("Your Key = ");
			scanf("%d", &key);
			deleteLeafNode(head, key);
			break;
		case 'f': case 'F':
			printf("Your Key = ");
			scanf("%d", &key);
			ptr = searchIterative(head, key);
			if(ptr != NULL)
				printf("\n node [%d] found at %p\n", ptr->key, ptr);
			else
				printf("\n Cannot find the node [%d]\n", key);
			break;
		case 's': case 'S':
			printf("Your Key = ");
			scanf("%d", &key);
			ptr = searchRecursive(head->left, key);
			if(ptr != NULL)
				printf("\n node [%d] found at %p\n", ptr->key, ptr);
			else
				printf("\n Cannot find the node [%d]\n", key);
			break;

		case 'i': case 'I':
			inorderTraversal(head->left);
			break;
		case 'p': case 'P':
			preorderTraversal(head->left);
			break;
		case 't': case 'T':
			postorderTraversal(head->left);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 1;
}

int initializeBST(Node** h) {

	/* if the tree is not empty, then remove all allocated nodes from the tree*/
	if(*h != NULL)
		freeBST(*h);

	/* create a head node */
	*h = (Node*)malloc(sizeof(Node));
	(*h)->left = NULL;	/* root */
	(*h)->right = *h;
	(*h)->key = -9999;
	return 1;
}



void inorderTraversal(Node* ptr) //중위 순환 방식
{
	if(ptr) { 
		inorderTraversal(ptr->left); //재귀를 통해 ptr의 왼쪽자식을 가르킨다.
		printf(" [%d] ", ptr->key); // ptr의 key값 출력
		inorderTraversal(ptr->right); //재귀를 통해 ptr의 오른쪽 자식을 가르킨다.
	}
}

void preorderTraversal(Node* ptr) //재귀 전위 순환 방식 
{
	if(ptr) {
		printf(" [%d] ", ptr->key); // ptr의 key값 출력
		preorderTraversal(ptr->left); //재귀를 통해 ptr의 왼쪽자식을 가르킨다.
		preorderTraversal(ptr->right); //재귀를 통해 ptr의 오른쪽 자식을 가르킨다.
	}
}

void postorderTraversal(Node* ptr) //재귀 후위 순환 방식
{
	if(ptr) {
		postorderTraversal(ptr->left); //재귀를 통해 ptr의 왼쪽자식을 가르킨다.
		postorderTraversal(ptr->right); //재귀를 통해 ptr의 오른쪽 자식을 가르킨다.
		printf(" [%d] ", ptr->key); // ptr의 key값 출력
	}
}


int insert(Node* head, int key) // 삽입 함수
{
	;
}
int deleteLeafNode(Node* head, int key)
{
	;
}

Node* searchRecursive(Node* ptr, int key)// 재귀 방식으로 search 하는 함수 구현
{
	;
}
Node* searchIterative(Node* head, int key) // 순회방식 search 함수 구현
{
 	 ;
}

void freeNode(Node* ptr) // 노드의 메모리 할당 해제하는 함수
{
 	 ;
}

int freeBST(Node* head) // 이진탐색트리 메모리 할당해제하는 함수
{

  	 ;
}



