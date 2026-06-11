#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); i++)
#define all(a) (a).begin(),(a).end()
#define SORT(a) sort(all(a))
#define rSORT(a, i) sort(all(a),(i))

using ll = long long;
constexpr ll INF = 10000000000;
constexpr ll MOD = 1000000007;

using namespace std;

int main() {
	ll n; cin >> n;

	ll max_a = 0;
	ll aiueoon = 0;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;

		if (max_a < x) {
			max_a = x;
			aiueoon = y;
		}
	}
	cout << max_a + aiueoon << endl;
}