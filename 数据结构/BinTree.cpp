#include<cstdio>
#include<cstdlib>
#include <stack>

using namespace std;
struct BinTreeNode;
typedef struct BinTreeNode* PBinTreeNode;
typedef char DateType;
typedef struct BinTreeNode* BinTree;  //ֱ�ӽ�����������Ϊָ��ڵ��ָ������
typedef BinTree* PBinTree;   //ʵ��Ӧ���н���������Ϊ��������ʱ��������Ҫ���ݶ��������ڵ�ָ��ĵ�ַ 

//����ʵ�ֶ�����
struct BinTreeNode{    
	DateType info;
	PBinTreeNode llink;
	PBinTreeNode rlink;
}; 

//���ؽڵ�p�����ӽڵ�ĵ�ַ
PBinTreeNode leftChild_link(PBinTreeNode p){
	if(p != NULL)
		return p->llink;
	else return NULL;
} 

//���ؽڵ�p�����ӽڵ�ĵ�ַ
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

//��������
void preOrder(BinTree t){
	if (t == NULL)  return ;
	printf("%c\n",t->info);
	preOrder(t->llink);
	preOrder(t->rlink);
}
//�������� 
void inOrder(BinTree t){
	if(t == NULL) return ;
	inOrder(t->llink);
	printf("%c\n",t->info);
	inOrder(t->rlink);
}

//�������
int Deep_preOrder(BinTree t){            //�ݹ� 
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
int Deep_postOrder1(BinTree t){           //�ǵݹ�
	int deep = 0;
	Elem stnode;
	stack<Elem> s;
	PBinTreeNode p = t;                   //����ʱ��ǰҪ����Ķ����� 
	if(t == NULL)              
		return -1;                        //�������Ϊ-1 
	do{                         //ÿ�δ�ѭ������һ�ö�����ȥ���� 
		while(p != NULL){
			stnode.t = p;
			stnode.tag = 1;  
			s.push(stnode);	  //��һ����ջ
			p = p->llink;     //ѭ��ת�� 
		}
		while(!s.empty()){
			deep = s.size()-1>deep?s.size()-1:deep;
			stnode = s.top();s.pop();  //��ջ
			p = stnode.t;
			if(stnode.tag == 1){
				stnode.tag = 2;
				s.push(stnode);       //�ڶ�����ջ
				p = p->rlink;         //ѭ��ת�� 
				break;                //ֹͣ��ջ 
			}
		}
	}while(!s.empty());
	return deep;
}


//���Ӷ���
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
	//����
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











