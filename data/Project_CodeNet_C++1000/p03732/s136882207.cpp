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


	int N, W;
	cin >> N >> W;
	map<ll, ll> MAP;

	MAP[0] = 0;
	rep(i, N) {
		int w, v;
		cin >> w >> v;
		map<ll, ll> MAP2;
		for (auto itr : MAP) {
			MAP2[itr.first + w] = itr.second + v;
		}
		for (auto itr : MAP2) {
			if (MAP[itr.first] < itr.second) MAP[itr.first] = itr.second;
		}
	}

	ll saidai = 0;
	for (auto itr : MAP) {
		if (itr.first <= W) saidai = max(saidai, itr.second);
	}
	co(saidai);

	Would you please return 0;
}