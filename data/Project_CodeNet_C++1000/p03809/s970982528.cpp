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
const int maxn=100005;
int n,num,head[maxn],t[maxn<<1],ne[maxn<<1],deg[maxn];
int a[maxn],root;
bool godie=0;
inline void addedge(int x,int y){
	ne[++num]=head[x];head[x]=num;t[num]=y;
	ne[++num]=head[y];head[y]=num;t[num]=x;
}
inline i64 dfs(int x,int f){
	if(deg[x]==1){
		return a[x];
	}i64 sum=0,maxi=0;
	forE(i,x)if(t[i]!=f){
		i64 v=dfs(t[i],x);
		sum+=v;maxi=max(maxi,v);
	}
	if(sum<a[x]){
		godie=1;
		return 0;
	}
	i64 del=min(sum/2,sum-maxi);
	if(sum-a[x]>del){
		godie=1;
		return 0;
	}
	sum-=(sum-a[x])*2;
	//assert(sum>=0);
	return sum;
}
int main(){
	read(n);
	rep(i,1,n)read(a[i]);
	rep(i,1,n)head[i]=-1;
	rep(i,1,n-1){
		int x,y;read(x);read(y);
		addedge(x,y);
		deg[x]++;deg[y]++;
	}
	int rt=0;
	rep(i,1,n)if(deg[i]!=1){
		rt=i;break;
	}
	if(rt==0){
		if(a[1]==a[2]){
			puts("YES");
		}else{
			puts("NO");
		}return 0;
	}
	i64 x=dfs(rt,-1);
	if(x==0&&!godie){
		puts("YES");
	}else{
		puts("NO");
	}
	return 0;
}
