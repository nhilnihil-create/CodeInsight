#include <stdio.h>
int main(int argc, char *argv[])
{
	int t;
	scanf("%d",&t);
	int a[100000];
	int count[100005]={0};
	for(int i=0;i<t;i++){
		scanf("%d",&a[i]);
		if(a[i]==0){
			count[a[i]]++;
			count[a[i]+1]++;
		}
		else{
			count[a[i]]++;
			count[a[i]-1]++;
			count[a[i]+1]++;
		}
	}
	int max=count[0];
	for(int i=1;i<100000;i++){
		if(count[i]>max) max=count[i];
	}
	printf("%d",max);
	return 0;
}