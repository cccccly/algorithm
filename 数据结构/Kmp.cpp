#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct SeqString{ 		//˳���ַ��� 
	int MAXNUM;
	int n;
	char *c;
};
typedef struct SeqString *PSeqString;

PSeqString createNullStr_seq(int m){
	PSeqString pstr = (PSeqString)malloc(sizeof(struct SeqString));
	if(pstr != NULL){
		pstr->c = (char *)malloc(sizeof(char) * m);
		if(pstr->c!=NULL){
			pstr->n = 0;
			pstr->MAXNUM = m;
			return pstr;
		}
		else free(pstr);
	}
	printf("Out of space! \n");
	return NULL;
} 

int nood_match(PSeqString t,PSeqString p){
	int i,j;   //iΪp����ƥ�䴮�±꣬jΪt����Ŀ�괮�±�
	i = 0,j = 0;
	while(i < p->n&&j < t->n){
		if(t->c[j] == p->c[i]){
			i++,j++;
		}
		else {
			j = j-i+1;
			i = 0;
		}
	}
	if(i >= p->n)
		return (j - p->n + 1); //��һ��ƥ��ɹ���t���±�+1 
	else return 0;
}

int *makeNext(PSeqString p,int *next){
	int i =0,k = -1;
	next[0] = -1;
	while(i < p->n-1){
		
	}
} 
int main()
{
	double start,finish;
	start = clock();
	
	finish = clock();
	printf("time is %f",(finish-start)/CLOCKS_PER_SEC);
	return 0;
} 
