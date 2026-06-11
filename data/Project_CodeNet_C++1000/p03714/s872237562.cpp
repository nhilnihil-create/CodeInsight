#include <bits/stdc++.h>
typedef long long ll; 
 
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<ll> a(3 * N + 1);
	for (int i = 1; i <= 3 * N; i++) {
		cin >> a[i];
	}

	vector<ll> dl(N + 1, 0);
	priority_queue<ll, vector<ll>, greater<ll>> quel;
	for (int i = 1; i <= 2 * N; i++) {
		if (i <= N) {
			dl[0] += a[i];
			quel.push(a[i]);
		} else {
			dl[i - N] += dl[i - N - 1] + a[i];
			quel.push(a[i]);
			dl[i - N] -= quel.top();
			quel.pop();
		}
	}

	vector<ll> dr(N + 1, 0);
	priority_queue<ll, vector<ll>> quer;
	for (int i = 3 * N; i > N; i--) {
		if (i > 2 * N) {
			dr[0] += a[i];
			quer.push(a[i]);
		} else {
			int it = 2 * N + 1 - i;
			dr[it] += dr[it - 1] + a[i];
			quer.push(a[i]);
			dr[it] -= quer.top();
			quer.pop();
		}
	}

	ll res = -1e18;
	for (int i = 0; i <= N; i++) {
		res = max(res, dl[i] - dr[N - i]);
	}

	cout << res << endl;
	return 0;
}
