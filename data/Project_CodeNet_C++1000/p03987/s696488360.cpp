#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define ferrari ios_base::sync_with_stdio(false); cin.tie(NULL)

const ll mod = 1e9 + 7; // 998244353
const ll INF = 1e18;
const int inf = 2e9;
const int N = 200100;

int n, pos[N];
ll a[N], ans;
set<int> inds;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];	
		pos[a[i]] = i;
	}
	inds.insert(0);
	inds.insert(n + 1);
	for (int i = 1; i <= n; i++) {
		int R = *inds.upper_bound(pos[i]);
		auto it = inds.lower_bound(pos[i]);
		it--;
		int L = *it;
		ans += 1LL * (pos[i] - L) * (R - pos[i]) * i;
		inds.insert(pos[i]);
	}
	cout << ans << '\n';
}
