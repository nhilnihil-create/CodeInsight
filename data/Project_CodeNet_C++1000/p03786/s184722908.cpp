#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
const ll INF = 1LL<<60;
//int INF = numeric_limits<int>::max();

int main(int, char**) {
	int n; cin >> n;
	priority_queue<ll, vector<ll>, greater<ll>> que;
	for (int i=0; i<n; i++) {
		ll a; cin >> a;
		que.push(a);
	}

	int ret=0;
	ll v = 0;
	for (int i=0; i<n; i++) {
		ll now = que.top();
		que.pop();
		if (2*v>=now) ret++;
		else ret = 0;
		v += now;
	}
	ret++;
	cout << ret << endl;
	return 0;
}