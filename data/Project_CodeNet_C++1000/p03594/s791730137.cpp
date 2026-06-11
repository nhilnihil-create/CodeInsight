#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=5e2+10;
int a[maxn][maxn];
inline int read(){
	int x=0,flag=1;
	char ch=getchar();
	while(!isdigit(ch) && ch!='-')ch=getchar();
	if(ch=='-')flag=-1,ch=getchar();
	while(isdigit(ch))x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return x*flag;
}
int main(){
	int i,j,n,m,k;
	n=read();m=read();k=read();
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++){
			if(((i+j)/k)&1)
				a[i][j]+=2;
			if(((m-j+i)/k)&1)
				a[i][j]+=1;
		}
	for(i=1;i<=n;i++,puts(""))
		for(j=1;j<=m;j++){
			if(a[i][j]==0) printf("Y");
			if(a[i][j]==1) printf("G");
			if(a[i][j]==2) printf("B");
			if(a[i][j]==3) printf("R");
		}
	return 0;
}