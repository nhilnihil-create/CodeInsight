#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 102000;
int n,p[N],q[N];ll a[N],b[N];bool vis[N];
int main() {
	read(n);rep(i,1,n)read(a[i]);
	per(i,n,1)a[i]-=a[i-1];
	ll m,k;read(m);read(k);
	rep(i,1,n)q[i]=i;
	while(m--){int x;read(x);swap(q[x],q[x+1]);}
	rep(i,1,n)p[q[i]]=i;
	//a(k)-->b
	rep(i,1,n)if(!vis[i]){
		static int s[N];int len=0;
		for(int u=i;!vis[u];u=p[u])s[++len]=u,vis[u]=1;
		rep(j,1,len)b[s[(j+k)%len==0?len:(j+k)%len]]=a[s[j]];
	}
	
	rep(i,1,n)b[i]+=b[i-1],printf("%lld\n",b[i]);
	return 0;
}
