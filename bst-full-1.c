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
	 Node* newNode = (Node*)malloc(sizeof(Node));//입력받은 key값을 넣을 새로운 노드 생성
    newNode->key = key;//Newnode->key에 입력받은 key값 대입
    newNode->left = NULL;//newNode->left은 NULL
    newNode->right = NULL;//newNode->right은 NULL

    if (head->left == NULL) {//입력받은 노드가없다면 즉 처음 노드를 입력하면
        head->left = newNode;//head->left에 newnode연결
        return 1;
    }

    /* head->left is the root */
    Node* ptr = head->left;//ptr은 head->left가 가르키는 노드

    Node* parentNode = NULL;//parentNode를 NULL로설정
    while (ptr != NULL) {//ptr이 NULL이 아닐때 까지 반복

       /* if there is a node for the key, then just return */
        if (ptr->key == key) return 1;//ptr의key값이랑 입력받은 key값이 같은경우 함수 종료

        /* we have to move onto children nodes,
         * keep tracking the parent using parentNode */
        parentNode = ptr;//parentNode가 ptr노드랑 같게해줌

        /* key comparison, if current node's key is greater than input key
         * then the new node has to be inserted into the right subtree;
         * otherwise the left subtree.
         */
        if (ptr->key < key)//ptr의 key값이 입력받은 key값보다 작은경우
            ptr = ptr->right;//ptr을 ptr->right로 바꿔줌 만약 ptr->right가 NULL이라면 while문 탈출
        else//ptr의 key값이 입력받은 key값보다 큰경우
            ptr = ptr->left;//ptr을 ptr->left로 바꿔줌 만약 ptr->left가 NULL이라면 while문 탈출
    }

    /* linking the new node to the parent */
    if (parentNode->key > key)//parentNode의 key값이 입력받은 key값보다 작은경우
        parentNode->left = newNode;//parentNode의 왼쪽자식을 새로만든 노드로 만듬
    else
        parentNode->right = newNode;//parentNode의 오르쪽자식을 새로만든 노드로 만듬
    return 1;
}
int deleteLeafNode(Node* head, int key)
{
    if (head == NULL) {//head를 생성하지 않을경우 오류메세지 출력
        printf("\n Nothing to delete!!\n");
        return -1;
    }

    if (head->left == NULL) {//입력받은 노드가 없을경우 오류 메세지 출력
        printf("\n Nothing to delete!!\n");
        return -1;
    }

    /* head->left is the root */
    Node* ptr = head->left;//ptr을 head->left를 가르키게함


    /* we have to move onto children nodes,
     * keep tracking the parent using parentNode */
    Node* parentNode = head;//parentNode를 head노드로 설정

    while (ptr != NULL) {//ptr이 NULL이 될떄 까지 반복

        if (ptr->key == key) {//ptr의key값이 입력받은 key값이랑 같은경우
            if (ptr->left == NULL && ptr->right == NULL) {//ptr->left랑 ptr->right가 NULL일떄 실행 즉 ptr의 자식노드가 없을때실행

               /* root node case */
                if (parentNode == head)//입력받은 노드가 하나일때 그노드를 삭제할려할때
                    head->left = NULL;//head->left를 NULL해줌 

                 /* left node case or right case*/
                if (parentNode->left == ptr)//parentNode->left가ptr일때
                    parentNode->left = NULL;//parentNode->left을 NULL해줌
                else//parentNode->right가ptr일때
                    parentNode->right = NULL;//parentNode->right을 NULL해줌

                free(ptr);
            }
            else {
                printf("the node [%d] is not a leaf \n", ptr->key);//입력받은 key값이 없다
            }
            return 1;
        }

        /* keep the parent node */
        parentNode = ptr;//parentNode가 ptr노드랑 같게해줌

        /* key comparison, if current node's key is greater than input key
         * then the new node has to be inserted into the right subtree;
         * otherwise the left subtree.
         */
        if (ptr->key < key)//ptr->key값이 입력받은 key값보다 작은경우
            ptr = ptr->right;//ptr을 ptr->right로 바꿔줌
        else//ptr->key값이 입력받은 key값보다 큰경우
            ptr = ptr->left;//ptr을 ptr->left로 바꿔줌


    }

    printf("Cannot find the node for key [%d]\n ", key);//입력받은 key값이 없다는 메세지 출력
    return 1;
}

Node* searchRecursive(Node* ptr, int key)// 재귀 방식으로 search 하는 함수 구현
{
    if (ptr == NULL) // 만약 ptr 이 비어있다면
        return NULL; 

    if (ptr->key < key) // ptr의key값이 key값보다 작은경우
        ptr = searchRecursive(ptr->right, key); // 재귀함수를 통해서 ptr값을 ptr->right로 바꿔줌
    else if (ptr->key > key) // ptr의key값이 key값보다 큰경우
        ptr = searchRecursive(ptr->left, key); // 재귀함수를 통해서 ptr값을 ptr->left로 바꿔줌

      /* if ptr->key == key */
    return ptr; // ptr리턴

}
Node* searchIterative(Node* head, int key) // 순회방식 search 함수 구현
{
    /* root node */
    Node* ptr = head->left; // ptr=head->left로 설정

    while (ptr != NULL)// ptr의 끝까지 반복한다.
    {
        if (ptr->key == key) // ptr의 key값이 입력받은 key값이랑 같으면
            return ptr; // ptr 리턴

        if (ptr->key < key) ptr = ptr->right; //ptr의 key값이 key값보다 작은경우 ptr을 ptr->right로 바까줌
        else 
            ptr = ptr->left; // ptr을 ptr->left로 바까줌
    }

    return NULL;
}

void freeNode(Node* ptr) // 노드의 메모리 할당 해제하는 함수
{
 	 ;
}

int freeBST(Node* head) // 이진탐색트리 메모리 할당해제하는 함수
{

  	 ;
}



