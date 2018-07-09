#include<cstdio>
#include<cstdlib>
#include <stack>

using namespace std;
struct BinTreeNode;
typedef struct BinTreeNode* PBinTreeNode;
typedef char DateType;
typedef struct BinTreeNode* BinTree;  //直接将二叉树定义为指向节点的指针类型
typedef BinTree* PBinTree;   //实际应用中将二叉树作为参数传递时，可能需要传递二叉树根节点指针的地址 

//链表实现二叉树
struct BinTreeNode{    
	DateType info;
	PBinTreeNode llink;
	PBinTreeNode rlink;
}; 

//返回节点p的左子节点的地址
PBinTreeNode leftChild_link(PBinTreeNode p){
	if(p != NULL)
		return p->llink;
	else return NULL;
} 

//返回节点p的右子节点的地址
PBinTreeNode rightChild_link(PBinTreeNode p){
	if(p != NULL)
		return p->rlink;
	else return NULL;
} 

BinTree creatBinTree_link(){
	BinTree p = (BinTree)malloc(sizeof(struct BinTreeNode));
	if(p != NULL){
		p->llink = NULL;
		p->rlink = NULL; 
	}
	else 
		printf("Out of space! \n");
	return p;
}

//先序周游
void preOrder(BinTree t){
	if (t == NULL)  return ;
	printf("%c\n",t->info);
	preOrder(t->llink);
	preOrder(t->rlink);
}
//中序周游 
void inOrder(BinTree t){
	if(t == NULL) return ;
	inOrder(t->llink);
	printf("%c\n",t->info);
	inOrder(t->rlink);
}

//计算层数
int Deep_preOrder(BinTree t){            //递归 
	if(t == NULL) {
		return -1;
	}
	int ldeep = Deep_preOrder(t->llink);
	int rdeep = Deep_preOrder(t->rlink);
	return ldeep>rdeep?ldeep+1:rdeep+1;
}

typedef struct{
	int tag;
	BinTree t;
}Elem;
int Deep_postOrder1(BinTree t){           //非递归
	int deep = 0;
	Elem stnode;
	stack<Elem> s;
	PBinTreeNode p = t;                   //周游时当前要处理的二叉树 
	if(t == NULL)              
		return -1;                        //空树深度为-1 
	do{                         //每次大循环进入一棵二叉树去遍历 
		while(p != NULL){
			stnode.t = p;
			stnode.tag = 1;  
			s.push(stnode);	  //第一次入栈
			p = p->llink;     //循环转移 
		}
		while(!s.empty()){
			deep = s.size()-1>deep?s.size()-1:deep;
			stnode = s.top();s.pop();  //退栈
			p = stnode.t;
			if(stnode.tag == 1){
				stnode.tag = 2;
				s.push(stnode);       //第二次入栈
				p = p->rlink;         //循环转移 
				break;                //停止退栈 
			}
		}
	}while(!s.empty());
	return deep;
}


//增加儿子
void add_child(PBinTreeNode p,char c,char info){
	if(c == 'l'){
		p->llink = creatBinTree_link();
		p->llink->info = info;
	}
	else{
		p->rlink = creatBinTree_link();
		p->rlink->info = info;
	}	
}



/*------------------------------------------------------------------*/ 

int main()
{
	BinTree tree = creatBinTree_link();
	tree->info = 'A';
	char c[] = {'A','B','E','C','F','D','G','H','I','J','K','L'};
	//建树
	int cnt = 1;
	PBinTreeNode p = tree;
	add_child(p,'l','B');
	add_child(p,'r','G');
	p = p->llink;
	add_child(p,'l','E');
	add_child(p,'r','C');
	p = p->rlink;
	add_child(p,'l','F');
	add_child(p,'r','D');
	p = tree->rlink;
	add_child(p,'l','H');
	add_child(p,'r','L');
	p = p->llink;
	add_child(p,'l','I');
	p = p->llink;
	add_child(p,'r','J');
	p = p->rlink;
	add_child(p,'r','K');
	printf("%d\n",Deep_preOrder(tree));
	printf("%d\n",Deep_postOrder1(tree));
	return 0;
}











