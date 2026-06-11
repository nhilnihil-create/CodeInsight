#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9 + 7;
int main() {
	ll n,m;
	cin >> n >> m;
	if (2*n > m) cout << m/2 << '\n';
	else cout << n+(m-n*2)/4 << '\n';
	return 0;
}
