#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define maxn 300005
#define LL long long
using namespace std;

inline int rd(){
	int x=0,f=1;char c=getchar();
	while(c<'0' || c>'9') f=c=='-'?-1:1,c=getchar();
	while(c<='9' && c>='0') x=x*10+c-'0',c=getchar();
	return x*f;
}

int n,m,x[maxn],d[maxn],id[maxn],stk[maxn],top;
LL k,ans[maxn];
bool vis[maxn];

int main(){
	n=rd();
	for(int i=1;i<=n;i++) x[i]=rd(),d[i]=x[i]-x[i-1],id[i]=i;
	m=rd(); scanf("%lld",&k);
	for(int i=1,a;i<=m;i++) a=rd(),swap(id[a],id[a+1]);
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			top=0;
			for(int j=i;!vis[j];j=id[j]) stk[++top]=j,vis[j]=1;
			for(int j=1;j<=top;j++) ans[stk[j]]=d[stk[(k+j-1)%top+1]];
		}
	for(int i=1;i<=n;i++) ans[i]+=ans[i-1],printf("%.1lf\n",(double)ans[i]);
	return 0;
}