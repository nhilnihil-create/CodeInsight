#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); i++)
#define RREP(i, s, n) for (int i = s; i < (n); i++)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;
using ll = long long;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll MOD = 1000000007;
const ll INF = MOD * MOD;
const int inf = (1<<29);

int main() {

    ll x, y;
    cin >> x >> y;
    
    ll ans = 0;
    if (x<0&&y<0&&x>=y) {ans+=2;ans+=abs(x-y);}
	if (x<0&&y<0&&x<y) {ans+=abs(x-y);}
	if (x<0&&y>0) {ans=1;ans+=abs(y+x);}
	if (x>0&&y<0) {ans=1;ans+=abs(y+x);}
	if (x>0&&y>0&&x<=y) {ans+=abs(y-x);}
	if (x>0&&y>0&&x>y) {ans=2;ans+=abs(y-x);}
	if (!x||!y) {
		if (x>y) ans+=abs(y-x)+1;else ans+=abs(y-x);
	}
	printf("%lld",ans);
	return 0;
}