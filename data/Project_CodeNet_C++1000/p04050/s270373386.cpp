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
#define REP(_i,_a,_n) for(int _i=_a;_i<=_n;++_i)
#define PER(_i,_a,_n) for(int _i=_n;_i>=_a;--_i)
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
#define DB(_a) ({REP(_i,1,n) cout<<_a[_i]<<',';hr;})
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int P = 1e9+7, INF = 0x3f3f3f3f;
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}
ll qpow(ll a,ll n) {ll r=1%P;for (a%=P;n;a=a*a%P,n>>=1)if(n&1)r=r*a%P;return r;}
ll inv(ll x){return x<=1?1:inv(P%x)*(P-P/x)%P;}
inline int rd() {int x=0;char p=getchar();while(p<'0'||p>'9')p=getchar();while(p>='0'&&p<='9')x=x*10+p-'0',p=getchar();return x;}
//head



#ifdef __APPLE__
const int N = 1e2+50;
#else
const int N = 1e6+50;
#endif


int n,m,cnt,a[N];
int main() {
	scanf("%d%d",&n,&m);
	REP(i,1,m) scanf("%d",a+i);
	int x=0,y=0,z=0;
	REP(i,1,m) if (a[i]&1) {
		if (!x) x=i;
		else if (!y) y=i;
		else if (!z) z=i;
	}
	if (z) return puts("Impossible"),0;
	vector<int> v;
	if (m==1) {
		printf("%d\n",a[1]);
		if (a[1]!=1) v.pb(a[1]-1);
		v.pb(1);
	}
	else if (!x) {
		REP(i,1,m) printf("%d ",a[i]);hr;
		v.pb(a[1]-1);
		REP(i,2,m-1) v.pb(a[i]);
		v.pb(a[m]+1);
	}
	else if (!y) {
		printf("%d ",a[x]),v.pb(a[x]+1);
		REP(i,1,m) if (i!=x) printf("%d ",a[i]),v.pb(a[i]);
		--v.back(),hr;
	}
	else {
		printf("%d ",a[x]),v.pb(a[x]+1);
		REP(i,1,m) if (i!=x&&i!=y) printf("%d ",a[i]),v.pb(a[i]);
		printf("%d\n",a[y]);
		if (a[y]>1) v.pb(a[y]-1);
	}
	printf("%d\n",(int)v.size());
	for (int t:v) printf("%d ",t);hr;
}
