#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
	int n, a;
	cin >> n;
	vector<int>rate(8, 0);
	int highRate = 0;
	rep(i, n) {
		cin >> a;
		if (a <= 399)rate[0] = 1;
		else if (a <= 799)rate[1] = 1;
		else if (a <= 1199)rate[2] = 1;
		else if (a <= 1599)rate[3] = 1;
		else if (a <= 1999)rate[4] = 1;
		else if (a <= 2399)rate[5] = 1;
		else if (a <= 2799)rate[6] = 1;
		else if (a <= 3199)rate[7] = 1;
		else highRate++;
	}
	int kind = accumulate(all(rate), 0);
	cout << max(1,kind) << " " << kind + highRate;
	return 0;
}
