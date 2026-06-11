#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <deque>
#include <numeric>
#include <map>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF 1000000000000

using namespace std;
 
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

ll dp[101][301];
int main () {
	int N, W;
	cin >> N >> W;
	vector<ll> w(N), v(N);
	rep(i,N) {
		cin >> w[i] >> v[i];
	}
	ll offset = w[0];
	vector<ll> w0, w1, w2, w3;
	rep(i,N) {
		w[i] -= offset;
		if (w[i] == 0)
			w0.push_back(v[i]);
		else if (w[i] == 1)
			w1.push_back(v[i]);
		else if (w[i] == 2)
			w2.push_back(v[i]);
		else
			w3.push_back(v[i]);
	}
	sort(w0.rbegin(), w0.rend());
	sort(w1.rbegin(), w1.rend());
	sort(w2.rbegin(), w2.rend());
	sort(w3.rbegin(), w3.rend());
	ll ans = 0;
	rep (i,w0.size() + 1)
		rep (j,w1.size() + 1)
			rep(k,w2.size() + 1)
				rep(m,w3.size() + 1) {
					int all = i + j + k + m;
					ll cur_weight = all * offset + j + 2*k + 3*m;
					if (cur_weight > W)
						continue;
					ll sum_of_elems = accumulate(w0.begin(), w0.begin() + i, (ll)0)
									+ accumulate(w1.begin(), w1.begin() + j, (ll)0)
									+ accumulate(w2.begin(), w2.begin() + k, (ll)0)
									+ accumulate(w3.begin(), w3.begin() + m, (ll)0);
					ans = max(ans, sum_of_elems);
				}
	cout << ans << endl;
	return 0;
}