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



const int N = 1e3+10;


int main() {
	int n = rd();
	map<int,int> s;
	REP(i,1,n) ++s[rd()];
	if (n<=2) return puts("Possible"),0;

	{
	int mi = s.begin()->x, ma = s.rbegin()->x;
//	if (mi!=(ma+1)/2) return puts("Impossible"),0;
//	REP(i,mi+1,ma) {
//		int cnt = 0;
//		if (!s.count(i)||s[i]==1) return puts("Impossible"),0;
//	}
	if (s.begin()->y!=(ma&1)+1) return puts("Impossible"),0;
	}
	int len = s.rbegin()->x, L = 1, R = len+1;
	if (s.rbegin()->y<2) return puts("Impossible"),0;
	s.erase(len);
	int mi = 1e9;
	REP(i,2,len) {
		int d = max(abs(i-L),abs(i-R));
		if (s.count(d)) { 
			if (!--s[d]) s.erase(d);
		}
		else return puts("Impossible"),0;
		mi = min(mi, d+1);
	}


	puts("Possible");	
}







