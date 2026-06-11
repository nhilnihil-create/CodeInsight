#include <bits/stdc++.h>

using namespace std;

#define intt long long
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N = 100005;

int n, a, b;

int x[N];

int main() {

	FAST;

	cin >> n >> a >> b;
	for (int i = 0; i < n; i ++) {
		cin >> x[i];
	}
	intt ans = 0;
	for (int i = 1; i < n; i ++) {
		ans += min(1LL * (x[i] - x[i - 1]) * a, 1LL * b);
	}
	cout << ans << '\n';
	return 0;
}