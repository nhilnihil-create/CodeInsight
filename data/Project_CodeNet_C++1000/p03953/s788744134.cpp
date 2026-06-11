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
int a[maxn],b[maxn],op[maxn],n,m,ans[maxn],ori[maxn],tmp[maxn];
i64 res[maxn];
i64 k;
int main(){
    read(n);
    rep(i,1,n)read(a[i]);
    read(m);cin>>k;
    rep(i,1,m)read(op[i]);
    rep(i,1,n)b[i]=a[i]-a[i-1];
    rep(i,1,n)ori[i]=i;
    rep(i,1,n)ans[i]=i;
    rep(i,1,m)
    	swap(ori[op[i]],ori[op[i]+1]);
    for(;k;k>>=1){
    	if(k&1)rep(i,1,n)ans[i]=ori[ans[i]];
    	rep(i,1,n)tmp[i]=ori[ori[i]];
    	rep(i,1,n)ori[i]=tmp[i];
    }
    res[1]=a[1];
    rep(i,2,n)res[i]=res[i-1]+b[ans[i]];
    rep(i,1,n)printf("%lld.0\n",res[i]);
    return 0;
}
