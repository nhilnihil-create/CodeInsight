#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

signed main() {
	int w, h;
	cin >> w >> h;

	priority_queue<int, vector<int>, greater<int>> p, q;
	for (int i = 0; i < w; ++i) {
		int pi; cin >> pi;
		p.push(pi);
	}
	for (int i = 0; i < h; ++i) {
		int qi; cin >> qi;
		q.push(qi);
	}
	p.push(1000000000); q.push(1000000000); // 番兵

	++w; ++h;
	ll ans = 0;
	while (p.size() > 1 || q.size() > 1) {
		if (p.top() < q.top()) {
			ans += ((ll)p.top()) * h;
			--w;
			p.pop();
		}
		else {
			ans += ((ll)q.top()) * w;
			--h;
			q.pop();
		}
	}

	cout << ans << endl;

	return 0;
}