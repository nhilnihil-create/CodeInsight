#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 100005;
int n,m,a[MAXN],odd;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		scanf("%d",a+i);
		if(a[i]&1)++odd;
	}
	if(m==1){
		if(a[1]==1)printf("1\n1\n1\n");
		else printf("%d\n2\n%d %d\n",a[1],a[1]-1,1);
		return 0;
	}
	if(odd>2)puts("Impossible");
	else{
		bool flag=false;
		for(int i=1;i<=m;++i)
			if(a[i]&1){
				if(!flag)swap(a[i],a[1]),flag=true;
				else {swap(a[i],a[m]);break;}								   
			}
		int lenb=m;
		if(a[1]==1)--lenb;
		for(int i=1;i<=m;++i){
			printf("%d%c",a[i],(i==m)?'\n':' ');
		}
		printf("%d\n",lenb);
		for(int i=1;i<=m;++i){
			if(i==1){
				if(a[i]>1)printf("%d%c",a[i]-1,(i==m)?'\n':' ');
			}else if(i==m){
				printf("%d%c",a[i]+1,(i==m)?'\n':' ');
			}else{
				printf("%d ",a[i]);
			}
		}
	}
	return 0;
}
