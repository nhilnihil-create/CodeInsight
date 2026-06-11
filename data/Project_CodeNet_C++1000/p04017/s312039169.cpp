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
int n, l, q, x[N];
int f[21][N];

int main() {
	scanf("%d", &n);
	REP(i,1,n) scanf("%d",x+i);
	scanf("%d%d", &l, &q);
	int now = n;
	PER(i,1,n) { 
		while (x[now]-x[i]>l) --now;
		f[0][i] = now;
		REP(j,1,20) f[j][i]=f[j-1][f[j-1][i]];
	}
	REP(i,1,q) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (x>y) swap(x,y);
		int ans = 0;
		PER(i,0,20) if (f[i][x]<y) {
			x = f[i][x];
			ans ^= 1<<i;
		}
		printf("%d\n", ans+1);
	}
}






