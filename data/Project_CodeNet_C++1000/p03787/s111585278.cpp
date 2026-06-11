#include<bits/stdc++.h>
#define N 100005
#define LL long long
using namespace std;
int n,m,f[N],sz[N],w[N],cir[N],A,B,C;
int find(int x){ while(f[x]) x=f[x]; return x;}
int path(int x){ int s=0; while(f[x]) s^=w[x],x=f[x]; return s;}
int main()
{
	int i,x,y,p,q;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++) sz[i]=1;
	while(m--){
		scanf("%d %d",&x,&y);
		p=find(x),q=find(y);
		if(sz[p]<sz[q]) swap(p,q);
		if(p!=q)
			w[q]=path(x)^path(y)^1,f[q]=p,cir[p]|=cir[q],sz[p]+=sz[q];
		else{
			if(path(x)^path(y)) continue;
			else cir[p]=1;
		  }
	  }
	for(i=1;i<=n;i++)
		if(find(i)==i){
			if(sz[i]==1) C++;
			else if(cir[i]) A++;
			else B++;
		  }
	LL ans=1LL*C*C+2LL*C*(n-C)+2LL*A*B+1LL*A*A+2LL*B*B;
	cout<<ans;
	return 0;
}
