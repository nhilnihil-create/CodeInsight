#include<map>
#include<set>
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

/*
vll v;
vll times;
ll const MAX = 200005;
ll a[MAX];
ll tbl[MAX][12];


void pd(ll k) {
	for (ll i = 2; i*i <= k; i++) {
		if (k%i == 0) {
			v.push_back(i);
			k /= i;
			ll cnt = 1;
			while (k%i == 0) {
				cnt++;
				k /= i;
			}
			times.push_back(cnt);
		}
	}
	if (k != 1) {
		v.push_back(k);
		times.push_back(1);
	}
}

ll pow_minus(ll k) {
	if (k % 2 == 1) {
		return 1;
	}
	else {
		return -1;
	}
}
ll bit_cnt(ll k) {
	ll ans = 0;
	while (k > 0) {
		ans += (k & 1);
		k >>= 1;
	}
}


ll f(ll bit) {

}

int main() {
	ll n, k;
	cin >> n >> k;
	pd(k);
	ll ans = 0;
	ll max_bit = (1 << v.size());
	for (ll bit = 0; bit < max_bit; bit++) {
		ans += pow_minus(bit_cnt(bit)) * f(bit);
	}
}
*/

ll a[500];
int main() {
	ll n;
	cin >> n;
	REP(i, 1, n) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	reverse(a + 1, a + n + 1);
	ll max_v = a[1];
	ll cnt = 1;
	ll bef = a[1];
	bool evenflag = (max_v % 2 == 0);
	REP(i, 2, n) {
		ll cur = a[i];
		
		if (cur == bef) {
			cnt++;
			if (cur == max_v / 2 && evenflag && cnt >= 2) {
				cout << "Impossible" << endl;
				return 0;
			}
			else if (cur == max_v / 2 + 1 && !evenflag && cnt >= 3) {
				cout << "Impossible" << endl;
				return 0;
			}
		}
		else {
			if (bef - cur != 1 || cnt == 1 || cur < (1 + max_v) / 2) {
				cout << "Impossible" << endl;	
				return 0;
			}
			cnt = 1;
		}
		bef = cur;
	}
	cout << "Possible" << endl;
}