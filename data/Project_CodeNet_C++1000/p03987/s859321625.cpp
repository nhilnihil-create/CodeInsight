#include<iostream>
#include<set>
#include<algorithm>

using namespace std;

typedef long long ll;

int N;
ll a[200000 + 10];

ll ans = 0;
ll num_to_pos[200000 + 10];

int main() {
	cin >> N;
	fill(num_to_pos, num_to_pos + N, -1);
	for (int i = 0; i < N; i++)cin >> a[i], num_to_pos[a[i]] = i;

	set <ll> donepos;
	for (ll i = 1; i <= N; i++) {
		if (donepos.size() == 0) {
			ans += (num_to_pos[i] + 1) * (N - num_to_pos[i]) * i;
			donepos.insert(num_to_pos[i]);
		}
		else {
			ll l = -1, r = N;
			donepos.insert(num_to_pos[i]);
			if (donepos.find(num_to_pos[i]) != donepos.begin()) {
				auto befnow = donepos.find(num_to_pos[i]);
				befnow--;
				l = *befnow;
			}
			auto befend = donepos.end();
			befend--;
			if (donepos.find(num_to_pos[i]) != befend) {
				auto nxtnow = donepos.find(num_to_pos[i]);
				nxtnow++;
				r = *nxtnow;
			}
			ans += (num_to_pos[i] - l) * (r - num_to_pos[i]) * i;
		}
	}
	cout << ans << endl;
	return 0;
}