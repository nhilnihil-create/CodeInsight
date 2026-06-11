#include <bits/stdc++.h>
#define INF 2147483647
#define INF_LL 9223372036854775807
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

int main() {
	ll N, A, B;
	cin >> N >> A >> B;
	vector<ll> h(N);
	for (int i = 0; i < N; i++)cin >> h[i];
	sort(h.begin(), h.end());
	ll r = h[N - 1] / B;
	ll ans = INF_LL;
	for(int i = 0; i < 500; i++) {
		ll damage = B * r;
		ll l_d = r;
		for (int j = 0; j < N; j++) {
			if (h[j] <= damage)continue;
			l_d -= ceil((double)(h[j] - damage) / (double)(A - B));
		}

		if (l_d < 0) r += ceil((double)(h[N - 1] / B) / pow(2, i));
		else if (l_d > 0) {
			ans = min(r, ans);
			r -= ceil((double)(h[N - 1] / B) / pow(2, i));
		}
		else {
			ans = min(r, ans);
			break;
		}
	}

	cout << ans << endl;
	return 0;
}