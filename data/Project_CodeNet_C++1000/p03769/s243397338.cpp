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
Vi solve(ll n){
	if(n==1)return Vi{};
	if(n&1){Vi s=solve(n-1);s.insert(s.begin(),SZ(s)+1);return s;}
	Vi s=solve(n/2);s.pb(SZ(s)+1);return s;
}

int main() {
	ll n;read(n);Vi s=solve(n+1);
	printf("%d\n",2*SZ(s));
	rep(i,0,SZ(s)-1)printf("%d ",s[i]);
	rep(i,0,SZ(s)-1)printf("%d ",i+1);
	return 0;
}
