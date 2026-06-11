#include <bits/stdc++.h>
using namespace std;
 
long long n, x, ans = INT64_MAX, res;
vector<long long> a, b;
 
int main() {
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		a.push_back(tmp);
		b.push_back(tmp);
	}
	for(int k = 0; k < n; k++) {
		res = k * x;
		for (int i = 0; i < n; i++) {
			b[i] = min(b[i], a[(i + n - k) % n]);
			res += b[i];
		}
		ans = min(ans, res);
	}
	cout << ans << '\n';
	return 0;
}
