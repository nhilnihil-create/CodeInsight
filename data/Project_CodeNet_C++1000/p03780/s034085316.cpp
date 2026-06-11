#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout << (x) << " "
#define ce(x) cerr << (x) << "\n"
#define cesp(x) cerr << (x) << " "
#define pb push_back
#define mp make_pair
#define Would
#define you
#define please


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	
	int N, K;
	cin >> N >> K;

	int A;
	map<ll, ll> MAP;

	rep(i, N) {
		cin >> A;
		MAP[A]++;
	}

	int C[5001][5001] = {};
	int k = 0;
	C[0][0] = 1;
	for (auto itr2 : MAP) {
		ll kazu = itr2.second;
		rep(i, K) {
			if (C[k][i]) {
				rep1(ii, kazu) {
					ll kari = i + itr2.first * ii;
					if (kari <= K) {
						C[k + 1][kari] = 1;
					}
				}
				C[k + 1][i] = 1;
			}
		}
		k++;
	}



	int iranai = 0;
	int k1 = 0;
	for (auto itr : MAP) {

		if (itr.first < K) {
			int B[10001] = {};

			int OK = 0;
			int k2 = 0;
			rep(i, K + 1) {
				B[i] = C[k1][i];
			}
			for (auto itr2 : MAP) {
				if (k1 <= k2) {
					ll kazu = itr2.second;
					if (itr.first == itr2.first) kazu--;
					vector<int> V;
					rep(i, K) {
						if (B[i]) {
							rep1(ii, kazu) {
								ll kari = i + itr2.first * ii;
								if (kari <= K) {
									V.pb(kari);
								}
							}
						}
					}
					for (auto itr3 : V) {
						B[itr3] = 1;
					}

					for (int i = K - itr.first; i < K; i++) {
						if (B[i] == 1) OK = 1;
					}
					if (OK) break;
				}
				k2++;
			}
			if (OK == 0) {
				iranai += itr.second;
			}
		}
		k1++;
	}

	co(iranai);

	Would you please return 0;
}