#include <bits/stdc++.h>
using namespace std;
const int N=100010;
int fi[N*2],ne[N*2],la[N*2],a[N*2];
int i,j,k,n,m,x,y,t,f[N],ans,cnt[N],K;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9'){f=ch=='-'?-f:f;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
void add(int x,int y){
	k++;a[k]=y;
	if (fi[x]==0)fi[x]=k;else ne[la[x]]=k;
	la[x]=k;
}
int dfs(int x){
	int la=0,ch=0;
	for (int i=fi[x];i;i=ne[i])la=max(la,dfs(a[i])),ch++;
	la++;
	if (x==1)return 0;
	if (la>=K&&f[x]!=1)ans+=1,la=-1;
	return la;
}
int main(){
	n=read();K=read();
	for (i=1;i<=n;i++)f[i]=read();
	if (f[1]!=1)ans++,f[1]=1;
	for (i=2;i<=n;i++)add(f[i],i);
	dfs(1);
	printf("%d\n",ans);
	return 0;
}