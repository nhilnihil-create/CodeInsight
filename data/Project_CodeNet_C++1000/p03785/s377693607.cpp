#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
	ll n, c, k,t,cnt=0,sec=0,ans=0;
	cin >> n >> c >> k;
	vector<ll>cust(n);
	rep(i, n)cin >> cust[i];
	sort(all(cust));
	rep(i, n) {
		if (i == n - 1) {
			ans++;
			break;
		}
		if (cnt == 0) {
			sec = cust[i] + k;
			cnt++;
		}
		if (cnt == c) { cnt = 0; ans++; continue; }
		if (i < n-1 &&cust[i + 1] <= sec) {
			cnt++;
		}
		else {
			cnt = 0;
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}

