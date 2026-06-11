#include<bits/stdc++.h>
using namespace std;
int n,a[100005],x,y,deg[100005];
int fir[100005],nxt[200005],to[200005],cnt=0;
int f[100005],root;

int read(){
	int x=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x;
}

void shit(){
	puts("YES");exit(0);
}

void fuck(){
	puts("NO");exit(0);
}

void dfs(int x,int F){
	int sum=0,maxn=0,res,use,son=0;
	for(int i=fir[x];i;i=nxt[i]){
		if(to[i]==F) continue;
		dfs(to[i],x);
		maxn=max(f[to[i]],maxn);
		sum+=f[to[i]];
		son++;
	}
	if(!son){
		f[x]=a[x];
		return;
	}
	res=sum-maxn;
	if(x!=root){
		if(a[x]>sum) fuck();	
		if(res<maxn) use=res;
		else use=sum/2;
		if(use<sum-a[x]) fuck();
		f[x]=2*a[x]-sum;
		if(f[x]<0) fuck();
	}
	else{
		if(sum%2==1) fuck();
		if(res<maxn) fuck();
		if(sum/2!=a[x]) fuck();
	}
}

int main(){
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<n;i++){
		x=read(),y=read();
		deg[x]++,deg[y]++;
		to[++cnt]=y,nxt[cnt]=fir[x],fir[x]=cnt;
		to[++cnt]=x,nxt[cnt]=fir[y],fir[y]=cnt;
	}
	if(n==2){
		if(a[1]==a[2]) shit();
		else fuck();
	}
	for(int i=1;i<=n;i++) if(deg[i]>1) root=i;
	dfs(root,0);
	shit();
	
	return 0;
}