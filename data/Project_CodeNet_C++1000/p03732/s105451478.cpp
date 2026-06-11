#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <queue>
#define INF 1e9+7
#define rep(i,n) for(int i=0;i<n;i++)
#define NO cout<<"NO"<<endl;
#define YES cout << "YES"<<endl;
#define No cout << "No"<<endl;
#define Yes cout << "Yes"<<endl;
#define all(a) a.begin(),a.end()
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

int main() {

	ll n, W;
	ll ans = 0;
	vector<vector<ll>> w(100);
	ll mw;
	cin >> n >> W;

	rep(i, n) {
		ll a, b; cin >> a >> b;
		if (i == 0)mw = a;
		w[a - mw].push_back(b);
	}

	rep(i, 4) {
		sort(all(w[i]));
		reverse(all(w[i]));
	}

	for (int i = 0; i <= w[0].size(); i++) {
		for (int j = 0; j <= w[1].size(); j++) {
			for (int k = 0; k <= w[2].size(); k++) {
				for (int l = 0; l <= w[3].size(); l++) {
					ll sub = 0;
					if (mw*i + (mw + 1)*j + (mw + 2)*k + (mw + 3)*l <= W) {
						for (int x = 0; x < i; x++) {
							sub += w[0][x];
						}
						for (int x = 0; x < j; x++) {
							sub += w[1][x];
						}
						for (int x = 0; x < k; x++) {
							sub += w[2][x];
						}
						for (int x = 0; x < l; x++) {
							sub += w[3][x];
						}
						ans = max(sub, ans);
					}
				}
			}
		}
	}

	cout << ans << endl;

	return 0;
}