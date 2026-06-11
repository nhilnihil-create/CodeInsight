#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k, x, y, s;
	cin >> n >> k >> x >> y;
	if (n > k) {
		s = k * x + (n-k) * y;
	} else if (n==k){
		s = k*x;
	} else {
		s = n*x;
	}
	cout << s;
	return 0;
}
