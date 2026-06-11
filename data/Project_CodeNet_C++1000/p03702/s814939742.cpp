#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<bitset>
#include<ctime>
#include<deque>
#include<stack>
#include<functional>
#include<sstream>
//#include<cctype>
//#pragma GCC optimize(2)
using namespace std;
#define maxn 2000005
#define inf 0x7fffffff
//#define INF 1e18
#define rdint(x) scanf("%d",&x)
#define rdllt(x) scanf("%lld",&x)
#define rdult(x) scanf("%lu",&x)
#define rdlf(x) scanf("%lf",&x)
#define rdstr(x) scanf("%s",x)
typedef long long  ll;
typedef unsigned long long ull;
typedef unsigned int U;
#define ms(x) memset((x),0,sizeof(x))
const long long int mod = 1e9 + 7;
#define Mod 1000000000
#define sq(x) (x)*(x)
#define eps 1e-4
typedef pair<int, int> pii;
#define pi acos(-1.0)
//const int N = 1005;
#define REP(i,n) for(int i=0;i<(n);i++)
typedef pair<int, int> pii;
inline ll rd() {
	ll x = 0;
	char c = getchar();
	bool f = false;
	while (!isdigit(c)) {
		if (c == '-') f = true;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 1) + (x << 3) + (c ^ 48);
		c = getchar();
	}
	return f ? -x : x;
}

ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b, a%b);
}
int sqr(int x) { return x * x; }


/*ll ans;
ll exgcd(ll a, ll b, ll &x, ll &y) {
	if (!b) {
		x = 1; y = 0; return a;
	}
	ans = exgcd(b, a%b, x, y);
	ll t = x; x = y; y = t - a / b * y;
	return ans;
}
*/

ll  n;
ll A, B;
ll h[maxn];
bool chk(ll x) {
	ll tot = 0;
	ll q = A - B;
	for (int i = 1; i <= n; i++) {
	
		if (h[i]-B*x <= 0)continue;
		else {
			ll tp = h[i] - B * x;
			if (tp%q)tot += (tp / q + 1);
			else tot += (tp / q);
		}
	}
	if (tot <= x)return true;
	else return false;
}

int main() {
//	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	cin >> A >> B;
	for (int i = 1; i <= n; i++)rdllt(h[i]);
	sort(h + 1, h + 1 + n);
	ll l = 1, r = 1e9 + 1;
	ll ans = 0;
	while (l <= r) {
		ll mid = (l + r) / 2;
		if (chk(mid))r = mid - 1, ans = mid;
		else l = mid + 1;
	}
	cout << ans << endl;
	return 0;
}