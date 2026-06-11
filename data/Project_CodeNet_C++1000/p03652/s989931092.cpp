#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <bitset>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tl3;



const int BIG_NUM = 1e9;
const ll INF = 1000000000000000000;
const ll MOD = 1e9 + 7;
//const ll MOD = 998244353;


int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			a[i][j]--;
		}
	}

	int ans = BIG_NUM;
	vector<bool> isHeld(m, true);
	for (int i = 0; i < m;) {
		map<int, int> cnt;

		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (isHeld[a[j][k]]) {
					cnt[a[j][k]]++;
					break;
				}
			}
		}

		int ma = 0;
		for (int j = 0; j < m; j++) {
			ma = max(ma, cnt[j]);
		}

		ans = min(ans, ma);
		for (int j = 0; j < m; j++) {
			if (cnt[j] == ma) {
				isHeld[j] = false;
				i++;
			}
		}

		
	}

	cout << ans << endl;
}