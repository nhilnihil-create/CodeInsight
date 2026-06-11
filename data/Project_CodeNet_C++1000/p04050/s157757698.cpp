#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

const int maxm=1e5+10;
int m,a[maxm],odd1,odd2;

int main(){
	scanf("%*d%d",&m);
	for(int i=1;i<=m;++i){
		scanf("%d",&a[i]);
		if(a[i]&1){
			if(odd2){
				puts("Impossible");
				return 0;
			}
			else if(odd1)
				odd2=i;
			else
				odd1=i;
		}
	}
	if(m==1){
		if(a[1]==1)
			printf("1\n1\n1\n");
		else
			printf("%d\n2\n1 %d\n",a[1],a[1]-1);
	}
	else{
		if(odd1)swap(a[1],a[odd1]);
		if(odd2)swap(a[m],a[odd2]);
		for(int i=1;i<=m;++i)
			printf("%d ",a[i]);
		if(a[m]==1){
			printf("\n%d\n",m-1);
			printf("%d ",a[1]+1);
			for(int i=2;i<m;++i)
				printf("%d ",a[i]);
			puts("");
		}
		else{
			printf("\n%d\n",m);
			printf("%d ",a[1]+1);
			for(int i=2;i<m;++i)
				printf("%d ",a[i]);
			printf("%d\n",a[m]-1);
		}
	}
	return 0;
}