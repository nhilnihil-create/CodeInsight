#include<map>
#include<set>
#include<bitset>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<chrono>
#include<stack>
#include<fstream>
#include<list>
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

ll const MAX = 100005;
ll p[MAX], q[MAX];

int main() {
	ll h, w;
	cin >> w >> h;
	REP(i, 1, w) {
		cin >> p[i];
	}
	REP(j, 1, h) {
		cin >> q[j];
	}
	SORT(p, w);
	SORT(q, h);
	p[w + 1] = q[h + 1] = 1e11;
	ll cnt_p = 1; ll cnt_q = 1;
	ll ans = 0;
	while (cnt_p <= w || cnt_q <= h) {
		if (p[cnt_p] < q[cnt_q]) {
			ans += (h + 2 - cnt_q)*p[cnt_p];
			//cout << (w+2-cnt_q) << " " << p[cnt_p] << "?" << endl;
			cnt_p++;
		}
		else {
			ans += (w + 2 - cnt_p)*q[cnt_q];	
			//cout << h + 2 - cnt_p << " " << q[cnt_q] << "!" << endl;

			cnt_q++;
		}
		//cout << ans << endl;
	}
	cout << ans << endl;
}