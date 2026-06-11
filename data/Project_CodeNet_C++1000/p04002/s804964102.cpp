#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
typedef unsigned int ui;
int main() {
	int i, j,k;
	ll h, w; int n, a, b;
	cin >> h >> w >> n;
	map<P, int> m;
	vector<P> s;
	for (i = 0; i < n; i++) {
		cin >> a >> b;
		for (j = a - 1; j <= a + 1; j++) {
			for (k = b - 1; k <= b + 1; k++) {
				if (j >= 2 && k >= 2 &&j <= h-1 &&k <= w-1) {
					P p = make_pair(j, k);
					s.push_back(p);
					m[p]++;
				}
			}
		}
	}
	if (s.empty()) {
		cout << (h - 2)*(w - 2) << endl;
		for (i = 1; i < 10; i++) {
			cout << 0 << endl;
		}
		return 0;
	}
	sort(s.begin(), s.end());
	int len = s.size(); int out[10] = {};
	out[m[s[0]]]++;
	for (i = 1; i < len; i++) {
		if (s[i] != s[i - 1]) {
			out[m[s[i]]]++;
		}
	}
	ll sum = (h-2)*(w-2);
	for (i = 1; i < 10; i++) {
		sum -= out[i];
	}
	cout << sum << endl;
	for (i = 1; i < 10; i++) {
		cout << out[i] << endl;
	}
	return 0;
}