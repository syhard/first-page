#include <stdio.h>
int main()
{
    int N,a[100005];
    scanf("%d",&N);
    for(int i=0;i<N;i++){
    	scanf("%d",&a[i]);
	}
	int e=0,max=-1001;
	for(int i=0;i<N;i++){
		e+=a[i];
		if(e>max)
			max=e;
		if(e<0){
			e=0;
		}
	}
	printf("%d",max);
 	return 0;      
