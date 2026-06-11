#include <bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define ff first
#define ss second
#define P 1000000007
#define in(x, a, b) (a <= x && x < b)

using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
const ll inf = 1000000001, INF = (ll)1e18 + 1;

void solve() {
	int n;
	cin >> n;
	
	vector<ll> a(3 * n);
	for(int i = 0; i < 3 * n; i++) cin >> a[i];
	
	vector<ll> pre(3 * n), suf(3 * n);
	ll sum = 0;
	multiset<ll> s;
	for(int i = 0; i < n; i++) {
		s.insert(a[i]);
		sum += a[i];
	}
	
	pre[n - 1] = sum;
	for(int i = n; i < 2 * n; i++) {
		if(a[i] > *s.begin()) {
			sum -= *s.begin();
			s.erase(s.begin());
			s.insert(a[i]);
			sum += a[i];
		}
		
		pre[i] = sum;
	}
	
	sum = 0;
	s.clear();
	for(int i = 3 * n - 1; i >= 2 * n; i--) {
		s.insert(a[i]);
		sum += a[i];
	}
	
	suf[2 * n] = sum;
	for(int i = 2 * n - 1; i > n - 1; i--) {
		auto it = s.end();
		it--;
		if(a[i] < *it) {
			sum -= *it;
			s.erase(it);
			s.insert(a[i]);
			sum += a[i];
		}
		
		suf[i] = sum;
	}
	
	ll ans = -INF;
	for(int i = n - 1; i < 2 * n; i++) {
		ans = max(ans, pre[i] - suf[i + 1]);
	}
	
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	solve();
    return 0;
}	