#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define forE(i,x) for(int i=head[x];i!=-1;i=ne[i])
using namespace std;
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned u32;
typedef pair<int,int> pin;
#define mk(a,b) make_pair(a,b)
#define lowbit(x) ((x)&(-(x)))
#define sqr(a) ((a)*(a))
#define clr(a) (memset((a),0,sizeof(a)))
#define ls ((x)<<1)
#define rs (((x)<<1)|1)
#define mid (((l)+(r))>>1)
#define pb push_back
#define w1 first
#define w2 second
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
inline void judge(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
}
/*******************************head*******************************/ 
const int maxn=200005;
int n,m;
int head[maxn],t[maxn<<1],ne[maxn<<1],num,col[maxn],size[maxn];
int sumb,numb,sumn,numn;
i64 ans=0;
inline bool dfs(int x, int fa, int c){
	if(col[x]!=-1)return col[x]==c;
	col[x]=c;size[x]=1;
	bool res=true;
	forE(i,x){
		if(col[t[i]]==-1)
			res&=dfs(t[i],x,c^1),size[x]+=size[t[i]];
		else
			res&=dfs(t[i],x,c^1);
	}
	return res;
}
inline void addedge(int x,int y){
	ne[++num]=head[x];head[x]=num;t[num]=y;
	ne[++num]=head[y];head[y]=num;t[num]=x;
}
int main(){
	read(n);read(m);rep(i,1,n)head[i]=-1;
 	rep(i,1,m){
		int x,y;
		read(x);read(y);
		addedge(x,y);
	}
	memset(col,-1,sizeof(col));
	rep(i,1,n)if(col[i] == -1){
		bool flag=dfs(i, 0, 0);
		int sz=size[i];
		if(sz>1){
			if(flag)
				sumb+=sz,numb+=1;
			else
				sumn+=sz,numn+=1;
		}
	}
	ans=1ll*n*n;
	ans-=1ll*(sumb+sumn)*(sumb+sumn);
	ans+=1ll*(numb+numn)*(numb+numn);
	ans+=1ll*numb*numb;
	printf("%lld\n",ans);
	return 0;
}