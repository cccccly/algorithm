#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <>
struct Node;
typedef struct Node* PNode;
typedef int DateType;
struct Node{           /* å•é“¾è¡¨èŠ‚ç‚¹ç»“æ„*/
	DateType info;
	PNode link;
};

typedef struct Node* LinkList;    /* å•é“¾è¡¨ç±»å‹ */ 

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

int deleteP_link(LinkList llist, PNode p){
	PNode q;
	for(q = llist->link;q != NULL;q = q->link){
		if(q->link == p)
			break;
	}
	if(q){
		q->link = p->link;
		free(p);
		return 1;
	}
	else return 0;
}
//µ¥Á´±íÈ¥³ıÖØ¸´ÔªËØ
void we_are_diffrent(LinkList llist){
	for(PNode q = llist;q != NULL;q = q->link){
		
	}
} 

//Ë«ÏòÁ´±í

struct DoubleNode;
typedef struct DoubleNode * PDoubleNode;
struct DoubleNode{  //Ë«Á´±í½Úµã 
	DateType info;
	PDoubleNode llink,rlink; 
}; 

struct DoubleList{  //Ë«Á´±íÀàĞÍ 
	PDoubleNode head; 
	PDoubleNode rear;
};

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
	printf("\n");

	
	return 0;	
} 
