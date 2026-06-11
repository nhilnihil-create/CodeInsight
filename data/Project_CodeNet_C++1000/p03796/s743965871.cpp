#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	ll c = 1;
	for (int i = 1; i <= n; i++) {
		c *= i;
		c %= 1000000007;
	}
	cout << c << endl;
}