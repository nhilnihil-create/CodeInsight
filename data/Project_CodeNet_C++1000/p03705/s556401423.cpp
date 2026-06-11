#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
	ll n, a, b;
	cin >> n >> a >> b;
	if (a > b || a != b && n == 1)cout << 0 << endl;
	else if (n == 1 && a == b)cout << 1 << endl;
	else {
		ll lb = b - a;
		lb *= (n - 2LL);
		cout << lb + 1 << endl;
	}
	return 0;
}
