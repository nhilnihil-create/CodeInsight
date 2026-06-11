#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;
int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long C[51][51], sum[51], max_sum = 0, cnt = 0, v[50];
	int n, a, b, m = 1;
	C[0][0] = 1;
	for(int k = 1; k <= 50; ++k) {
		C[k][0] = C[k][k] = 1;
		for(int i = 1; i < k; ++i)
			C[k][i] = C[k - 1][i] + C[k - 1][i - 1];
	}
	cin >> n >> a >> b;
	for(int i = 0; i < n; ++i)
		cin >> v[i];
	sort(v, v + n);
	sum[0] = 0;
	for(int i = 1; i <= b; ++i)
		sum[i] = sum[i - 1] + v[n - i];
	for(int i = a; i <= b; ++i) {
		if(max_sum * i < sum[i] * m) {
			max_sum = sum[i];
			m = i;
		}
	}
	cout << fixed << setprecision(15) << max_sum /(double)m << '\n';
	for(int k = a; k <= b; ++k) {
		if(sum[k] * m == max_sum * k) {
			int i = n - k, j = n - k;
			while(i > 0 && v[i - 1] == v[i]) --i;
			while(j < n - 1 && v[j + 1] == v[j]) ++j;
			cnt += C[j - i + 1][k - n + j + 1];
		}
	}
	cout << cnt << '\n';
	return 0;
}