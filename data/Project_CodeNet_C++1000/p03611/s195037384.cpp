#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAX = 100005;

int main() {
	int n;
	cin >> n;
	vector<int> x(MAX);
	rep(i, n) {
		int a;
		cin >> a;
		if (a > 0) x[a - 1]++;
		x[a]++;
		x[a + 1]++;
	}
	int mx = 0;
	rep(i, MAX) mx = max(mx, x[i]);
	cout << mx << endl;
	return 0;
}