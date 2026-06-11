#include<iostream>
#include<map>
#include<algorithm>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

const int vx[9] = { -1, -1, 0, 1, 1, 1, 0, -1, 0 }, 
          vy[9] = { 0, 1, 1, 1, 0, -1, -1, -1, 0 };

int main() {
	ll H, W;
	int N;
	ll ans[10]{};

	map<P, int> cnt;

	cin >> H >> W >> N;
	for (int i = 0; i < N; i++) {
		ll a, b;
		cin >> a >> b;
		a--, b--;
		for (int j = 0; j < 9; j++) {
			ll nx = a + vx[j], ny = b + vy[j];
			if (nx < 1 || ny < 1 || nx >= H - 1 || ny >= W - 1)continue;
			cnt[P(nx, ny)]++;
		}
	}
	ll tmp = (H - 2) * (W - 2);
	for (auto it = cnt.begin(); it != cnt.end(); it++) {
		ans[(*it).second]++;
		tmp--;
	}
	cout << tmp << endl;
	for (int i = 1; i <= 9; i++) {
		cout << ans[i] << endl;
	}

	return 0;
}