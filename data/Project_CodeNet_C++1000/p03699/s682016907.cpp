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
	vector<int>point(n),notTen;
	rep(i, n) {
		cin >> s;
		point[i] = s;
		if (s % 10 != 0)notTen.push_back(s);
	}
	sum = accumulate(all(point), 0);
	sort(all(notTen));
	if (sum % 10 != 0)cout << sum << endl;
	else {
		if (notTen.size())cout << sum - notTen[0] << endl;
		else cout << 0 << endl;
	}
	return 0;
}
