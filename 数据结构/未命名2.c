/*1.先设计一个基本账户类，
成员有：账号、姓名、开户日期，并有静态成员：年利率。
功能有：计算月利息和更改利率。 
再通过继承基本账户类设计一个储蓄账户类，储蓄账户类中增加密码、地址、最小余额等成员变量，
并增加一些银行账户经常用到的成员函数。要求：
（1）类中的成员函数具有输入、输出储户上述信息的功能。
（2）将账号设计为不可更改。
（3）修改密码时要提供原密码。
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
struct Student{
	char name[10];
};

void f(struct Student stu,char *name){
	strcpy(stu.name,name);
	printf("%s\n",stu.name);
}

int main()
{
	struct Student stu1;
	char name[10] = "sssss";
	scanf("%s",name);
	char *s = name;
	printf("%s\n",name);
	f(stu1,name);
	
	return 0;
}







