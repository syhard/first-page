// 2£ºÊä 3£ºÊä  4£ºÓ®  5£ºÊä 6£ºÓ® 7£ºÓ®  8£ºÊä 
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
