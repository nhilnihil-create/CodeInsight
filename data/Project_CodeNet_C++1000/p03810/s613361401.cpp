#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int gcd(int a, int b) {
	return b? gcd(b, a % b): a;
}

const int maxn = 1e5 + 10;
int n, a[maxn];

int solve() {
	int cnt = 0;
	ll sum = 0;
	bool flag = false;
	for (int i = 0; i < n; ++i) {
		cnt += a[i] & 1;
		sum += a[i];
		if (a[i] == 1)
			flag = true;
	}
	if (flag)
		return ((sum - n) & 1);
	if (cnt >= 2) {
		if ((cnt & 1) == (n & 1))
			return 0;
		return 1;
	}
	if ((n + 1) & 1)
		return 1;
	int g = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] & 1)
			a[i]--;
		g = gcd(g, a[i]);
	}
	for (int i = 0; i < n; ++i)
		a[i] /= g;
	return solve() ^ 1;
}

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	if (n < 3) {
		if (n == 1)
			if (a[0] & 1)
				cout << "Second\n";
			else
				cout << "First\n";
		else
			if ((a[0] + a[1]) & 1)
				cout << "First\n";
			else
				cout << "Second\n";
		return 0;
	}
	if (solve())
		cout << "First\n";
	else
		cout << "Second\n";
	return 0;
}
