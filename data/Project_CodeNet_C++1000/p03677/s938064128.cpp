#include"bits/stdc++.h"
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
const long long mod =998244353;
const long long inf = 1ll << 61;
typedef pair<char, int> P;
struct edge { int to; int to2; int cost; };
int a[100006];
int imos[200006];
signed main() {
	int n, m; cin >> n >> m;
	rep(i, n)cin >> a[i];
	rep(i, n - 1) {
		if (a[i] > a[i + 1]) {
			a[i + 1] += m;
		}
			imos[a[i] + 1]--;
			imos[a[i + 1]] += a[i + 1] - a[i];
			imos[a[i + 1] + 1] -= a[i + 1] - a[i] - 1;
			if (a[i + 1] > m)a[i + 1] -= m;
	}
	rep(i, 2*m)imos[i + 1] += imos[i];
	rep(i, 2*m)imos[i + 1] += imos[i];
	rep(i, m)imos[i] += imos[m + i];
	int sum = 0;
	rep(i, n - 1) {
		sum += (a[i + 1] - a[i] + m) % m;
	}
	rep(i, m)imos[i] += sum;
	int mn = inf;
	rep(i, m) {
		if (mn > imos[i]) {
			mn = imos[i];
		}
	}
	cout << mn << endl;
}
