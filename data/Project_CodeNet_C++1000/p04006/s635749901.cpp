#include <bits/stdc++.h>
#define len(v) ((int)((v).size()))
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define chmax(x, v) x = max((x), (v))
#define chmin(x, v) x = min((x), (v))
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int nbElem; cin >> nbElem;
	ll shiftCost; cin >> shiftCost;
	vector<ll> vec(nbElem);
	for (int i = 0; i < nbElem; ++i) {
		cin >> vec[i];
	}

	ll res = 1e18;
	vector<vector<ll>> costTake(nbElem, vector<ll>(nbElem, 1e18));
	for (int x = 0; x < nbElem; ++x) {
		for (int i = 0; i < nbElem; ++i) {
			chmin(costTake[x][(i+x)%nbElem], vec[i]);
		}
		ll sub = shiftCost*x;
		for (int i = 0; i < nbElem; ++i) {
			if (x > 0) chmin(costTake[x][i], costTake[x-1][i]);		
			sub += costTake[x][i];
		}
		chmin(res, sub);
	}
	cout << res << "\n";
}
