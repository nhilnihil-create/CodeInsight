#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define $ system("pause")
#define MOD ll(1e9 + 7)
#define MAXN 100010
#define LG 20
#define inf (ll)1e9

template<typename T> inline T smin(T &a, const T &b) { return a > b ? a = b : a; }
template<typename T> inline T smax(T &a, const T &b) { return a < b ? a = b : a; }
inline void add(ll &l, const ll &r) { l = (l + r) % MOD; }
ll gcd(ll v, ll u) { return u ? gcd(u, v % u) : v; }
ll po(ll v, ll u) { return u ? (po(v * v % MOD, u >> 1) * (u & 1 ? v : 1) % MOD) : 1; }

ll n;
int cnt = 1;
vector<int> gg;

ll ente[50][50];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int i = 0; i < 50; i++) {
		ente[0][i] = ente[i][i] = 1;
		for(int j = 1; j < i; j++) {
			ente[j][i] = ente[j][i - 1] + ente[j - 1][i - 1];
		}
	}
	cin >> n;
	while (n) {
		if (n <= (1e6)) {
			ll best = 0;
			int a = 0, b = 0, c = 0, d = 0;
			int e = 0; int f = 0;
			for (int i = 1; i <= 20; i++)
				for (int j = 1; j <= 20; j++)
					for (int k = 1; k <= 20; k++)
						for (int i_ = 0; (i + i_) <= 20; i_++)
							for (int j_ = 0; (j + j_) <= 20; j_++)
								for (int k_ = 0; (k + k_) <= 20; k_++) {
									ll res = 1ll << (i + i_ - 1);
									res += 1ll << (j + j_ - 1);
									res += 1ll << (k + k_ - 1);
									res -= 3;
									res += (ente[i][i + i_]) * (ente[j][j + j_]) * (ente[k][k + k_]);
									res -= (ente[i][i + i_] - 1);
									res -= (ente[j][j + j_]) - 1;
									res -= (ente[k][k + k_]) - 1;
									res -= 1;
									if (res > n)
										break;
									if (res > best) {
										best = res;
										a = i;
										b = j;
										c = k;
										d = i_;
										e = j_;
										f = k_;
									}

						
								}
			int ff = 3;
			if (a + d <= 1) {
				a = 0; d = 0;
				ff--;
			}
			if (b + e <= 1) {
				b = 0;
				e = 0;
				ff--;
			}
			if (c + f <= 1) {
				c = 0;
				f = 0;
				ff--;
			}
			for (int i = 0; i < a; i++)
				gg.push_back(cnt);
			for (int i = 0; i < b; i++)
				gg.push_back(cnt + 1);
			for (int i = 0; i < c; i++)
				gg.push_back(cnt + 2);
			for (int i = 0; i < d; i++)
				gg.push_back(cnt);
			for (int i = 0; i < e; i++)
				gg.push_back(cnt + 1);
			for (int i = 0; i < f; i++)
				gg.push_back(cnt + 2);
			cnt += ff;
			n -= best;
			continue;
		}
		ll best = 0;
		int a = 0, b = 0, c = 0, d = 0;
		for (int i = 1; i <= 40; i++) {
			for (int j = 1; j <= 40; j++) {
				for (int i2 = 0; (i + i2) <= 40; i2++) {
					for (int j2 = 0; (j + j2) <= 40; j2++) {
						ll res = 1ll << (i + i2 - 1);
						res += 1ll << (j + j2 - 1);
						res -= 2;
						res += (ente[i][i + i2] - 1) * (ente[j][j + j2] - 1);
						if (res <= n && res > best) {
							best = res;
							a = i;
							b = j;
							c = i2;
							d = j2;
						}
					}
				}
			}
		}
		n -= best;
		if (a + c <= 1) {
			a = 0;
			c = 0;
		}
		if (b + d <= 1) {
			b = 0;
			d = 0;
		}
		for (int i = 0; i < a; i++)
			gg.push_back(cnt);
		for (int i = 0; i < b; i++)
			gg.push_back(cnt + 1);

		for (int i = 0; i < c; i++)
			gg.push_back(cnt);
		for (int i = 0; i < d; i++)
			gg.push_back(cnt + 1);
		cnt += 2;
	}

	cout << gg.size() << endl;
	for (auto e : gg)
		cout << e << ' ';
	//$;
	return 0;
}