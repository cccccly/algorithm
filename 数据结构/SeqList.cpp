#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INF unsigned(-1)>>1
typedef int DateType;
typedef struct SeqList* PSeqList;

struct SeqList{
	int MAXNUM;
	int n;
	DateType *element;
}; 

//���������б� 
PSeqList createNullList_seq(int m){
	PSeqList palist = (PSeqList)malloc(sizeof(struct SeqList));
	if (palist != NULL){
		palist -> element = (DateType *)malloc(sizeof(DateType) * m);
		if (palist -> element){
			palist -> MAXNUM = m;
			palist -> n = 0;
			return palist;
		}
		else free(palist);
	}
	printf("Out of space!\n"); /*�����ڴ�ʧ��*/
	return NULL; 
}

//��palist��ָ˳����У��±�Ϊ p ��Ԫ�غ����ֵΪ x ��Ԫ�� 
int insertPost_seq(PSeqList palist,int p,DateType x){
	int i;
	if(palist ->n >= palist ->MAXNUM){
		printf("Overflow!\n");            /*���*/
		return 0;
	} 
	if(p <0 || p > palist ->n){
		printf("Not exist!\n");           /*�������±�Ϊp��Ԫ��*/
		return 0; 
	}
	for(i =palist ->n;i >= p +1;i--){
		palist ->element[i+1] = palist ->element[i];
	} 
	palist ->element[i] = x;
	palist ->n++;
	return 1;
}

PSeqList reverse_seq(PSeqList palist){
	int i,j;
	DateType t;
	for(i = 0,j = palist ->n -1;i <= palist ->n /2;i++,j--){
		t = palist ->element[i];
		palist ->element[i] = palist ->element[j];
		palist ->element[j] = t;
	}
	return palist;
}

//ɾ��Ԫ��x���������ǰŲ 
void deleteX_seq(PSeqList palist,DateType x){
	int cnt = 0;
	for(int i = 0;i <= palist->n-1;i++){
		if(palist->element[i] == x){
			cnt++;
		}
		else{
			palist->element[i-cnt] = palist->element[i];  //��ǰ�ƶ��ĸ�����Ϊ���ҵ�x�ĸ��� 
		}
	}
	palist->n = palist->n-cnt;
} 

int main()
{
	PSeqList palist;
	palist = createNullList_seq(100);   //������˳���ʱ������������һ����ڴ���ܺ�������ʱ��û�ط�����Ų�� 
	palist ->MAXNUM = 100;
	srand((unsigned int)time(NULL));
	for(int i = 0;i <= 50;i++){
		insertPost_seq(palist, i, rand()%6);
	}
	for(int i = 0;i <= palist->n-1;i++){
		printf("%d ",palist ->element[i]);
	}
	printf("\n");
	reverse_seq(palist);
	for(int i = 0;i <= palist->n-1;i++){
		printf("%d ",palist ->element[i]);
	}
	printf("\n");
	deleteX_seq(palist, 3);
	for(int i = 0;i <= palist->n-1;i++){
		printf("%d ",palist ->element[i]);
	}
	return 0;
}
