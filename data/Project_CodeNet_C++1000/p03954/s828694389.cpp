#include<bits/stdc++.h>
#define ll long long
#define N 500005
#define inf 1000000005
#define mod 998244353
#define put putchar('\n')
#define F(i,a,b) for (int i=a;i<=b;i++)
#define D(i,a,b) for (int i=a;i>=b;i--)
#define go(i,t) for (int i=head[t];i;i=Next[i])
#define sqr(x) ((x)*(x))
#define re register
#define mp make_pair
#define fi first
#define se second
#define M 10000005
#define pa pair <int,int>
using namespace std;
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read(){
	int x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void wr(ll x){if (x<0) {putchar('-');wr(-x);return;}if(x>=10)wr(x/10);putchar(x%10+'0');}
inline void wrn(ll x){wr(x);put;}inline void wri(ll x){wr(x);putchar(' ');}
inline void wrn(ll x,ll y){wri(x);wrn(y);}
int n,m,l,r,p[N];
bool pd(int a,int b,int c){return (p[a]>=c&&p[b]>=c);}
bool pd2(int a,int b,int c){return (p[a]<c&&p[b]<c);}
bool check(int x){
	F(i,0,n-1){
		if (pd(n+i,n+i+1,x)||pd(n-i,n-i-1,x)) return 1;
		if ((pd2(n+i,n+i+1,x))||(pd2(n-i,n-i-1,x))) return 0;
	}
	return (p[1]>=x);
}
signed main(){
	n=read();
	F(i,1,n*2-1) p[i]=read();
	l=1;r=n*2-1;
	while (l<r){
		int mid=(l+r+1)>>1;
		if (check(mid)) l=mid;
		else r=mid-1;
	}
	wrn(l);
	return 0;
}