#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
	int n, s,sum=0;
	cin >> n;
	vector<int>point(n);
	rep(i, n)cin >> point[i];
	sum = accumulate(all(point), 0);
	sort(all(point));
	if (sum % 10 != 0)cout << sum << endl;
	else {
		rep(i, n) {
			for (int j = i; j < n; j++) {
				if ((sum - point[j]) % 10 != 0) {
					cout << sum - point[j] << endl;
					return 0;
				}
			}
				sum -= point[i];
		}
		cout << sum << endl;
	}
	return 0;
}
