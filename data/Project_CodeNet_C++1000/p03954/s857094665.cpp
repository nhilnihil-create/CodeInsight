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
const int N = 222222;
int n,a[N],b[N];
int dis(int x, int y){return x-y>0?x-y:y-x;}
bool ck(){//a[1..2*n-1]
	bool flag=1;
	rep(i,1,2*n-2)flag&=a[i]!=a[i+1];
	if(flag){
		return (n-1+a[n])&1;
	}
	int v[2];rep(i,0,1)v[i]=1e9;
	rep(i,1,2*n-2)if(a[i]==a[i+1])
		umin(v[a[i]],min(dis(i,n),dis(i+1,n)));
	return v[1]<v[0];
}
int main() {
	read(n);rep(i,1,n*2-1)read(b[i]);
	int l=1,r=2*n-1;
	while(l<r){
		int mid=(l+r)>>1;
		rep(i,1,n*2-1)a[i]=b[i]>mid;
		if(ck())l=mid+1;else r=mid;
	}
	printf("%d",l);
	return 0;
}
