#include <bits/stdc++.h>
using namespace std;

const int N = 100005, M = N;
int n, m, a[N], g, o[M];
long long tp, fp, e[M];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		if(i == 1) continue;
		if(a[i - 1] < a[i]) {
			int ab = a[i] - a[i - 1];
			tp += ab;
			--o[a[i - 1] + 1];
			++o[a[i]];
			e[a[i]] += ab - 1;
		} else {
			int ab = m - a[i - 1] + a[i];
			tp += a[i];
			--o[1];
			++o[a[i]];
			e[a[i]] += ab - 1;
			--o[a[i - 1] + 1];
		}
	}
	for(int i = 1; i <= m; ++i) {
		fp = ((i == 1 || fp > tp) ? tp : fp);
		g += o[i];
		tp += e[i] + g;
	}
	cout << fp << endl;
	return 0;
}
