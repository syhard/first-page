// 2���� 3����  4��Ӯ  5���� 6��Ӯ 7��Ӯ  8���� 
#include<stdio.h>
int main()
{
	int a[50]={2,3};
	for(int i=2;i<50;i++){
		a[i]=a[i-1]+a[i-2];
	}
	int n,flag;
	while(scanf("%d",&n)&&n!=0){
		flag=1;
		for(int i=0;i<50;i++){
			if(a[i]==n){
				flag=0;
				break;
			}
		}
		if(!flag)
			printf("Second win\n");
		else
			printf("First win\n");
		
	}
 } 
