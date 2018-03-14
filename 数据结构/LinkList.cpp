#include <stdio.h>
#include <stdlib.h>
#include <iostream>
struct Node;
typedef struct Node* PNode;
typedef int DateType;
struct Node{           /*单链表节点结构*/
	DateType info;
	PNode link;
};

typedef struct Node* LinkList;    /* 单链表类型 */ 

LinkList createNullList_link(){
	LinkList llist = (LinkList)malloc(sizeof(struct Node));
	if(llist != NULL) llist ->link = NULL;
	else printf("Out of space!\n");
	return llist;
} 

int insertPost_link(LinkList llist,PNode p,DateType x){
	PNode q = (PNode)malloc(sizeof(struct Node));
	if(q == NULL) {
		printf("Out of space!!!\n");
		return 0; 
	}
	else {
		q ->info = x;q ->link = p ->link;p ->link =q;return 1;
	} 
}


int main()
{
	LinkList llist1 = createNullList_link();
	for(int i = 0;i <= 10;i++){      //initialize
		if(!insertPost_link(llist1,llist1,rand()%4+1))
			printf("insert wrong!!!\n");
	}
	for(PNode p = llist1->link;p != NULL;p = p->link){
		printf("%d ",p->info);
	}
	return 0;	
} 
