
// Problem : D - Decrease (Contestant ver.)
// Contest : AtCoder Regular Contest 079
// URL : https://atcoder.jp/contests/arc079/tasks/arc079_b
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define cerr if(1)cerr
#define size(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define temptts template <class T, class... Ts>

const int N = 1e6 + 1, mod = 1e9 + 7, inf = 2e9;

int n = 50;
ll k, kn, a[N];

int main() { cin.tie(0)->sync_with_stdio(0);
	cin >> k;
	kn = k / n;
	for (int i = 1; i <= n; i++) {
		a[i] = i + kn - 1;
	}
	kn = k % n;
	for (int i = n; i >= n - kn + 1; i--) {
		a[i]++;
	}
	cout << n << '\n';
	for (int i = 1; i <= n; i++) {
		cout << a[i] << ' ';
	}
}
