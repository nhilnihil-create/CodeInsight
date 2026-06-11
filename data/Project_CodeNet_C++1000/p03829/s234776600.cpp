#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAX_N = 1e5+7;

ll N, A, B;
ll X[MAX_N];

void input() {
	cin >> N >> A >> B;
	for(int i=0;i<N;i++) {
		cin >> X[i];
	}
}

void solve() {
	ll ans = 0;
	for(int i=1;i<N;i++) {
		ll cost;
		if((X[i]-X[i-1])*A < B) cost = (X[i]-X[i-1])*A;
		else cost = B;
		ans += cost;
	}
	cout << ans << endl;
}

int main() {
	input();
	solve();
}