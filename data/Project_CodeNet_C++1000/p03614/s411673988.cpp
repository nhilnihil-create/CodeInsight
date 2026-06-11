#include<stdio.h>
using namespace std;
int main(){
	int a[100050]={0},b[100050],c,i,j,n,m;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int times=0;
	for(i=1;i<=n;i++){
		if(a[i]==i){
			c=a[i];
			a[i]=a[i+1];
			a[i+1]=c;
			times++;
		}
	}	
	printf("%d\n",times);	
	return 0;
}