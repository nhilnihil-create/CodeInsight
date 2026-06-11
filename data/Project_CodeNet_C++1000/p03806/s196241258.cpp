#include <bits/stdc++.h>
using namespace std;

//https://atcoder.jp/contests/abc054/tasks/abc054_d

const int sm = 2e3;

int n, ma, mb, ans = 1e9;
bool flag = 0;
vector<pair<int, int>> as, bs;
int adp[sm + 1], bdp[sm + 1];

int main() {
	cin >> n >> ma >> mb;
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a *= mb;
		b *= ma;
		if (a > b)
			as.emplace_back(a - b, c);
		else if (b > a)
			bs.emplace_back(b - a, c);
		else {
			ans = min(ans, c);
			flag = 1;
		}
	}

	fill(adp + 1, adp + sm + 1, 1e9);
	fill(bdp + 1, bdp + sm + 1, 1e9);

	for (auto a : as)
		for (int i = sm; i >= a.first; i--)
			adp[i] = min(adp[i], adp[i - a.first] + a.second);
	for (auto b : bs)
		for (int i = sm; i >= b.first; i--)
			bdp[i] = min(bdp[i], bdp[i - b.first] + b.second);
	for (int i = 1; i <= sm; i++)
		if (adp[i] + bdp[i] < ans) {
			ans = adp[i] + bdp[i];
			flag = 1;
		}

	cout << (flag ? ans : -1) << endl;
}
