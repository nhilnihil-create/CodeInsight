#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cstring>
#include <bitset>
#include <functional>
#include <random>
#define REP(i,a,n) for(int i=a;i<=n;++i)
#define PER(i,a,n) for(int i=n;i>=a;--i)
#define hr putchar(10)
#define pb push_back
#define lc (o<<1)
#define rc (lc|1)
#define mid ((l+r)>>1)
#define ls lc,l,mid
#define rs rc,mid+1,r
#define x first
#define y second
#define io std::ios::sync_with_stdio(false)
#define endl '\n'
#define DB(a) ({REP(__i,1,n) cout<<a[__i]<<' ';hr;})
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int P = 1e9+7, INF = 0x3f3f3f3f;
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}
ll qpow(ll a,ll n) {ll r=1%P;for (a%=P;n;a=a*a%P,n>>=1)if(n&1)r=r*a%P;return r;}
ll inv(ll x){return x<=1?1:inv(P%x)*(P-P/x)%P;}
inline int rd() {int x=0;char p=getchar();while(p<'0'||p>'9')p=getchar();while(p>='0'&&p<='9')x=x*10+p-'0',p=getchar();return x;}
//head



const int N = 1e6+50;
char s[N],t[N];
int q, tr1[N<<2], tr2[N<<2];
int add(int x, int y) {
	if (!x||!y) return x+y;
	return x==y?"AB"[x=='A']:0;
}
void build(int tr[], char s[], int o, int l, int r) {
	if (l==r) tr[o]=s[l];
	else { 
		build(tr,s,ls),build(tr,s,rs);
		tr[o] = add(tr[lc],tr[rc]);
	}
}
int qry(int tr[], int o, int l, int r, int ql, int qr) {
	if (ql<=l&&r<=qr) return tr[o];
	if (mid>=qr) return qry(tr,ls,ql,qr);
	if (mid<ql) return qry(tr,rs,ql,qr);
	return add(qry(tr,ls,ql,qr),qry(tr,rs,ql,qr));
}
int main() {
	scanf("%s%s%d",s+1,t+1,&q);
	int c1,c2;
	build(tr1,s,1,1,c1=strlen(s+1));
	build(tr2,t,1,1,c2=strlen(t+1));
	REP(i,1,q) {
		int l1,r1,l2,r2;
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		puts(qry(tr1,1,1,c1,l1,r1)==qry(tr2,1,1,c2,l2,r2)?"YES":"NO");
	}
}






