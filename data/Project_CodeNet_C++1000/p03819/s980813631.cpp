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
const int maxn=300005;
int v[maxn],n,m;
inline void solve(int l,int r){
	for(int i=1,lastv=1e9,last;i<=r;i=last+1){
		if(i<=l)
			last=min(l/(l/i),r/(r/i));
		else
			last=r;
		if(l/i<lastv){
			v[l/i+1]++,v[min(lastv,r/i)+1]--;
			lastv=l/i;
		}
	}
}
int main(){
	read(n);read(m);
	rep(i,1,n){
		int l,r;read(l);read(r);
		solve(l-1,r);
	}
	rep(i,1,m)printf("%d\n",v[i]+=v[i-1]);
	return 0;
}
