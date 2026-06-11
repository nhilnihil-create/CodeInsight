#include<bits/stdc++.h>
#define N 12000000
using namespace std;
int tot,Next[N],v[N],h[N];
int l[N],r[N],q[N],siz[N],dep[N];
int p[N],son[N],O,ill,cnt;
int n,k;
int ans[N];
int add(int x,int y){
	tot++;
	Next[tot]=h[x];
	v[tot]=y;
	h[x]=tot;
	return 0;
}
int get_siz(int x,int fa){
	siz[x]=1;
	for(int i=h[x];i;i=Next[i]){
		if(p[v[i]]==1)continue;
		if(v[i]==fa)continue;
		get_siz(v[i],x);
		siz[x]+=siz[v[i]];
	}
	return 0;
}
int get_son(int x,int fa,int OO){
	son[x]=OO-siz[x];
	for(int i=h[x];i;i=Next[i]){
		if(p[v[i]]==1)continue;
		if(v[i]==fa)continue;
		get_son(v[i],x,OO);
		son[x]=max(son[x],siz[v[i]]);
	}
	if(son[x]<son[O])O=x;
	return 0;
}
int get_son(int x){
	son[O]=10000000;
	O=0;
	get_siz(x,0);
	get_son(x,0,siz[x]);
	return O;
}
int AA,BB;
int lfs(int x,int fa){
//	printf("%d\n",x);
	dep[x]=dep[fa]+1;
	siz[x]=1;
	AA=max(AA,dep[x]);
	for(int i=h[x];i;i=Next[i]){
		if(p[v[i]]==1)continue;
		if(v[i]==fa)continue;
		lfs(v[i],x);
		siz[x]+=siz[v[i]];
	}
	l[dep[x]]++;
	return 0;
}
int ifs(int x,int fa){
	dep[x]=dep[fa]+1;
	siz[x]=1;
	BB=max(BB,dep[x]);
	for(int i=h[x];i;i=Next[i]){
		if(p[v[i]]==1)continue;
		if(v[i]==fa)continue;
		ifs(v[i],x);
		siz[x]+=siz[v[i]];
	}
	r[dep[x]]++;
	return 0;
}
int afs(int x,int fa){
	if(dep[x]>k)return 0;
	ans[x]+=-r[min(k-dep[x],BB)]+l[min(k-dep[x],AA)]+1;
	for(int i=h[x];i;i=Next[i]){
		if(p[v[i]]==1)continue;
		if(v[i]==fa)continue;
		afs(v[i],x);
	}
	return 0;
}
int cfs(int x,int fa){
	dep[x]=dep[fa]+1;
	l[dep[x]]=0;
	for(int i=h[x];i;i=Next[i]){
		if(p[v[i]]==1)continue;
		if(v[i]==fa)continue;
		cfs(v[i],x);
	}
	return 0;
}
int ccfs(int x,int fa){
	dep[x]=dep[fa]+1;
	r[dep[x]]=0;
	for(int i=h[x];i;i=Next[i]){
		if(p[v[i]]==1)continue;
		if(v[i]==fa)continue;
		ccfs(v[i],x);
	}
	return 0;
}
int solve(int x){
	p[x]=1;
	AA=0,BB=0;
	dep[x]=0;
	for(int i=h[x];i;i=Next[i]){
		if(p[v[i]]==1)continue;
		lfs(v[i],x);
	}
	for(int i=1;i<=AA;i++)l[i]+=l[i-1];
	ans[x]+=l[min(AA,k)];
	for(int i=h[x];i;i=Next[i]){
		if(p[v[i]]==1)continue;
		BB=0;
		ifs(v[i],x);
		for(int i=1;i<=BB;i++)r[i]+=r[i-1];
		afs(v[i],x);
		ccfs(v[i],x);
	}
	for(int i=h[x];i;i=Next[i]){
		if(p[v[i]]==1)continue;
		cfs(v[i],x);
	}
	for(int i=h[x];i;i=Next[i]){
		if(p[v[i]]==1)continue;
		int o=get_son(v[i]);
		solve(o);
	}
	return 0;
}
int main(){
	scanf("%d%d",&n,&k);
	if(k%2==0){
		k/=2;
		for(int i=1;i<n;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			add(x,y);
			add(y,x);
		}
	solve(1);
	int O=0;
   	for(int i=1;i<=n;i++)O=max(O,ans[i]);
   	printf("%d\n",n-O-1);
	}
	else{
		for(int i=1;i<n;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			add(x,n+i);
			add(n+i,x);
			add(y,n+i);
			add(n+i,y);
		}
		int p=n;
		n=n+n-1;
		solve(1);
		int O=0;
		for(int i=n/2+2;i<=n;i++)O=max(O,ans[i]);
//		for(int i=1;i<=20;i++)printf("%d\n",ans[i]);
		if(O+1==n)printf("%d\n",0);
		else printf("%d\n",p-O/2-1);
	}
	return 0;
}