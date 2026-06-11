#include<map>
#include<bitset>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<stack>
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define SIZE(a) ll(a.size())
#define vll vector<ll> 
#define MEMSET(a, n, m) for(ll i=0;i<=n;i++) a[i] = m
#define BIT(n) (ll(1)<<n)
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end()) 
#define UNIQUE_ARRAY(a,n) n = unique(a + 1, a + x + 1) - a - 1
#define SORT(a,n) sort(a+1,a+n+1)
#define SORT_O(a,n,order) sort(a+1,a+n+1,order)
#define PER(i,y,x) for(ll i=y;i>=x;i--)
typedef long long ll;
using namespace std;
/*
struct point
{
long long dist; long long name;
bool operator<(const point& rhs) const {
return dist > rhs.dist;
}
};
*/

struct integ {
	ll num; ll val;
};
ll const MAX = 100005;
integ a[MAX];

bool order(integ x, integ y) {
	return x.num < y.num;
}

ll m_ = 0;

int main() {
	ll n;
	ll m;
	cin >> n >> m;
	REP(i, 1, n) {
		ll x, y;
		cin >> x >> y;
		a[i] = { x,y };
	}
	SORT_O(a, n, order);
	ll ans = 0;
	while (m >= (1 << m_)) {
		m_++;
	}
	while (m_ >= 0) {
		ll t = (1 << m_);
		ll cnt = 0;
		if ((t & m) != 0) {
			REP(i, 1, n) {
				if (a[i].num < t) {
					cnt += a[i].val;
				}
				if(a[i].num>=t) {
					a[i].num -= t;
				}
			}
			//cout << cnt << endl;
			ans = max(ans, cnt);
			/*
			REP(i, 1, n) {
				cout << a[i].num << " " << a[i].val << endl;
			}
			*/
		}
		m_--;
	}
	ll cnt = 0;

	REP(i, 1, n) {
			if (a[i].num == 0) cnt += a[i].val;
		}
	ans = max(cnt, ans);

	cout << ans << endl;
}