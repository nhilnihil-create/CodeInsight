#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n; cin >> n;
	deque<ll> dq;
	for (int i = 0; i < n; i++) {
		ll a; cin >> a;
		if (i % 2 == 0) dq.push_back(a);
		else dq.push_front(a);
	}
	if (n % 2 != 0) reverse(dq.begin(), dq.end());
	for (auto itr = dq.begin(); itr != dq.end(); ++itr) {
		cout << *itr << " ";
	}
	return 0;
}