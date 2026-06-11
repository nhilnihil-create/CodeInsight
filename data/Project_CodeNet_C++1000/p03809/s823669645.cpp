#include<bits/stdc++.h>
#define ll long long
using namespace std;
/*struct aaa{
	int x,y;
}b[200010];*/
int flag,n,m,tot,rt,b[200010],du[200010],e[200010],hd[200010],nt[200010],le[200010],re[200010],a[200010];
void build(int x,int y){
	tot++;
	e[tot]=y;
	nt[tot]=hd[x];hd[x]=tot;
}
void dfs(int x,int fa){
	int i,sum=0;
	for(i=hd[x];i;i=nt[i]){
		if(e[i]==fa)continue;
		dfs(e[i],x);
		sum+=b[e[i]];
		if(b[e[i]]>a[x]){
			flag=1;
		}
		//b[++m].x=le[e[i]];b[m].y=re[e[i]];
	}
	if(du[x]==1){
		b[x]=a[x];return;
	}
	b[x]=a[x]*2-sum;
	if(b[x]<0||b[x]>a[x])flag=1;
	/*m=0;
	for(i=hd[x];i;i=nt[i]){
		if(e[i]==fa)continue;
		b[++m].x=le[e[i]];b[m].y=re[e[i]];
	}
	/*if(!m){
		le[x]=re[x]=a[x];return;
	}
	int mx=0,op,sum=0;
	for(i=1;i<=m;i++){
	  re[i]+=b[i].y;
	  if(b[i].x>=mx)mx=b[i].x,op=i;
    }
    for(i=1;i<=m;i++)if(op!=i)sum+=b[i].y;
    if(sum>=b[op].x)le[i]=0;
     else le[i]=b[op].x-sum;*/
}
int main(){
	int i,x,y;
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	if(n==2){
		if(a[1]!=a[2])puts("NO");
		 else puts("YES");
		return 0;
	}
	
	for(i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		build(x,y);build(y,x);
		du[x]++;du[y]++;
	}
	for(i=1;i<=n;i++)if(du[i]>1)rt=i;
	//printf("%d\n",rt);
	dfs(rt,0);
	if(flag)return puts("NO"),0;
	if(b[rt]==0)puts("YES");
	 else puts("NO");
}