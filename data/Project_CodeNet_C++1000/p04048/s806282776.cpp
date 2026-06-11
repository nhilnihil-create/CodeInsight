#include <bits/stdc++.h>
#define int long long
using namespace std;
int solve(int a, int b) {
	// cout << a << ' ' << b << '\n';
	if(a < b) swap(a, b);
	if(b == 0) return 0;
	if(a % b == 0) return 2 * a - b;
	int res = a / b;

	return 2 * res * b +  solve(a % b, b);
}
int N, X;
signed main() {
	cin >> N >> X;
	cout << N + solve(N - X, X);
}
