#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <string>
#include <cmath>
#include <map>
#include <iomanip>
#include <utility>
#define INF 1000000009
#define LINF 1000000000000000009
#define double long double
#define all(a) a.begin(),a.end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<P, ll> PP;
typedef pair<ll, double> PD;
//ll mod = 1000000007;
//ll mod = 998244353;

int main() {
	ll n, x;
	cin >> n >> x;
	if (x == 1 || x == 2 * n - 1) {
		cout << "No" << endl;
		return 0;
	}
	vector<int> ans(2 * n - 1);
	ans[n - 2] = x - 1;
	ans[n - 1] = x;
	ans[n] = x + 1;
	ll base = 1;
	for (int i = n + 1; i < 2 * n - 1; i++) {
		if (base == x - 1) base += 3;
		ans[i] = base;
		base++;
	}
	for (int i = 0; i < n - 2; i++) {
		if (base == x - 1) base += 3;
		ans[i] = base;
		base++;
	}
	cout << "Yes" << endl;
	for (ll i : ans) cout << i << endl;
}