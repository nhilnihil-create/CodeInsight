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
#define DB(a) ({REP(__i,1,n) cout<<a[__i]<<',';hr;})
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
int n, a[N];

void calc() {
	ll sum = accumulate(a+1,a+1+n,0ll);
	if (!sum) puts("YES"),exit(0);
	ll sz = (ll)n*(n+1)/2;
	if (sum%sz) puts("NO"),exit(0);
	a[n+1] = a[1];
	ll cnt = sum/sz;
	REP(i,1,n) {
		if ((cnt-a[i+1]+a[i])%n) puts("NO"),exit(0);
		if ((cnt-a[i+1]+a[i])<0) puts("NO"),exit(0);
	}
	int p = min_element(a+1,a+1+n)-a;
	int now = 0;
	REP(d,p,n) a[d]-=++now;
	REP(d,1,p-1) a[d]-=++now;
}
int main() {
	scanf("%d",&n);
	REP(i,1,n) scanf("%d",a+i);
	REP(i,1,20) calc();
	puts("YES");
}






