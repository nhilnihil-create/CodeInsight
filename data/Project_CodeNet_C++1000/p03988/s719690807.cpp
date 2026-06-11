#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
inline int read(){
	int f=1,ans=0;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return f*ans;
}
const int MAXN=101;
int n,a[MAXN],maxn,num[MAXN];
void wrong(){printf("Impossible\n");exit(0);}
int main(){
	n=read();
	for(int i=1;i<=n;i++) a[i]=read(),num[a[i]]++,maxn=max(maxn,a[i]);
	int minn=(maxn+1)/2+1;
	if(maxn%2==1) if(num[minn-1]!=2) wrong();
	if(maxn%2==0&&num[minn-1]!=1) wrong();
	for(int i=1;i<minn-1;i++) if(num[i]) wrong();
	for(int i=minn;i<=maxn;i++) if(num[i]<2) wrong();
	printf("Possible\n"); 
}
