#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n + 1), b(n + 1), p(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}
	for (int i = 1; i <= n; i++) {
		a[i] = (n + 1) * i;
		b[i] = (n + 1) * (n - i + 1);
	}  
	for (int i = 1; i <= n; i++) {
		a[p[i]] += i;
	}
	for (int i = 1; i <= n; i++) {
		cout << a[i] << ' ';
	}
	cout << '\n';
	for (int i = 1; i <=  n; i++) {
		cout << b[i] << ' ';
	}
	cout << '\n';
} 