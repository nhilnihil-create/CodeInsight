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
const int N = 500500;
int n,a[N];
bool In(int x, int y){
	return x<=n&&y<=a[x];
}
int main() {
	read(n);rep(i,1,n)read(a[i]);sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	int q;
	rep(i,1,n)if(In(i,i))q=i;else break;
	bool ok=0;
	int l=q,r=1e9,pos=q;
	while(l<=r){
		int mid=(l+r)>>1;
		if(In(q,mid))pos=mid,l=mid+1;else r=mid-1;
	}
	ok|=pos-q&1;
	l=q,r=1e9,pos=q;
	while(l<=r){
		int mid=(l+r)>>1;
		if(In(mid,q))pos=mid,l=mid+1;else r=mid-1;
	}
	ok|=pos-q&1;
	printf("%s",ok?"First":"Second");
	return 0;
}
