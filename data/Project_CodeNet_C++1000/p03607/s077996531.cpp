#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
	int n,a;
	cin >> n;
	map<int, bool>mp;
	rep(i, n) {
		cin >> a;
		if (mp[a])mp.erase(a);
		else mp[a] = true;
	}
	cout << mp.size() << endl;
	return 0;
}
