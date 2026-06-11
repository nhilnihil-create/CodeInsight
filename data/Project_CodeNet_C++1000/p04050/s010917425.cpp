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
int n, m, a[N], b[N];

int main() {
	scanf("%d%d", &n, &m);
	vector<int> v[2];
	REP(i,1,m) { 
		int t;
		scanf("%d", &t);
		v[t&1].pb(t);
	}
	if (m==1) {
		if (n==1) return puts("1\n1\n1"),0;
		return printf("%d\n%d\n%d %d\n",n,2,1,n-1),0;
	}
	if (v[1].size()>2) return puts("Impossible"),0;
	if (v[1].size()==2) {
		a[1] = v[1][0], a[m] = v[1][1];
		if (a[1]>a[m]) swap(a[1],a[m]);
		b[1] = a[1]+1;
		REP(i,2,m-1) { 
			a[i] = v[0].back(), v[0].pop_back();
			b[i] = a[i];
		}
		b[m] = a[m]-1;
	}
	else if (v[1].size()==1) {
		a[1] = v[1][0], b[1] = a[1]+1;
		REP(i,2,m) {
			a[i] = v[0].back(), v[0].pop_back();
			b[i] = a[i];
		}
		b[m] = a[m]-1;
	}
	else {
		a[1] = v[0].back(), b[1] = a[1]+1;
		v[0].pop_back();
		REP(i,2,m) {
			a[i] = v[0].back(), v[0].pop_back();
			b[i] = a[i];
		}
		b[m] = a[m]-1;
	}
	REP(i,1,m) printf("%d ",a[i]);hr;
	if (!b[m]) --m;
	printf("%d\n",m);
	REP(i,1,m) printf("%d ",b[i]);hr;
}






