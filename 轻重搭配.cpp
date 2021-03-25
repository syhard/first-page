#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int a[500000];
	int n;
	scanf("%d",&n);
	int count=n;
	int m=n/2;
   for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
    	}
	 sort(a,a+n);
	for(int i=0;i<m;i++){
		for(int j=m+i;j<n;j++){
			if(2*a[i]<=a[j]){
				count--;;
				a[j]=0;
				break;
			}
		}
	}
	printf("%d",count);
 } 
