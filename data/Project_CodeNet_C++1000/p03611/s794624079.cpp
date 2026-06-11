#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
	int n,a,maxs=0;
	cin >> n;
	map<int, int>mp;
	rep(i, n) {
		cin >> a;
		mp[a - 1]++;
		mp[a]++;
		mp[a + 1]++;
	}
	for (auto m : mp) {
		maxs = max(maxs, m.second);
	}
	cout << maxs << endl;
	return 0;
}
