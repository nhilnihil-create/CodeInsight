#include<bits/stdc++.h>
#define int long long
#define rg register
#define file(x) freopen(x".txt","r",stdin);freopen(x".out","w",stdout);
using namespace std;
int read(){
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9') f=(c=='-')?-1:1,c=getchar();
    while(c>='0'&&c<='9') x=x*10+c-48,c=getchar();
    return f*x;
}
struct node {
	int to,next;
}a[200011];
int head[100011],cnt,x[100010],bin[101];
int fa[100011][32],ans=0,dep[100010];
void add(int x,int y){
	a[++cnt].next=head[x];
	a[cnt].to=y;
	head[x]=cnt;
}
void dfs(int x,int f){
	fa[x][0]=f;
	dep[x]=dep[f]+1;
	for(int i=1;i<=31;i++)
		fa[x][i]=fa[fa[x][i-1]][i-1];
	for(int i=head[x];i;i=a[i].next){
		int v=a[i].to;
		if(v==f) continue;
		dfs(v,x);
	}
}
main(){
	int n=read(),y;
	for(int i=1;i<=n;i++)
		x[i]=read();
	bin[0]=1;
	for(int i=1;i<=31;i++)
		bin[i]=bin[i-1]*2;
	x[n+1]=214748364700;
	int L=read();
	for(int i=1;i<n;i++)
		y=lower_bound(x+1,x+2+n,L+x[i]+1)-x-1,add(y,i);
	dfs(n,0);
	int Q=read();
	//cout<<fa[2][1];
//	cout<<bin[30];
	while(Q--){
		int A=read(),B=read(),p=min(A,B);
		if(A>B) swap(A,B);
		int ans=0;
		//cout<<B;
		for(int i=31;i>=0;i--)
			if(fa[A][i]<=B&&fa[A][i])
					A=fa[A][i],ans+=bin[i];//cout<<A<<" ";
//cout<<ans<<endl;
		if(A<B) ans++;
		cout<<ans<<endl;
//		if(ans==0) cout<<fa[p][0]<<" "<<dep[B]<<endl;
	}
    return 0;
}