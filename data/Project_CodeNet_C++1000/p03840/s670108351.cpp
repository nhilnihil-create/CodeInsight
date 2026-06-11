#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 7;

ll cnt[N], ans;

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	for (int i = 0; i < N; i++)
		cin >> cnt[i];
	ans += 2 * cnt[1];
	cnt[1] = 0;

	
	ll maxi = 0;
	for (int i = 0; i <= min({1LL, cnt[0], cnt[3], cnt[4]}); i++) {
		ll X = 6 * i;
		
		X += 4 * ((cnt[3] - i) / 2);
	
		X += 4 * ((cnt[4] - i) / 2);
	
		X += 4 * ((cnt[0] - i) / 2);

		maxi = max(maxi, X);
	}

	cout << (ans + maxi) / 2;
}
