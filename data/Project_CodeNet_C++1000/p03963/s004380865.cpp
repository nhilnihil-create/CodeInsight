#include<bits/stdc++.h>

using namespace std;

int main() {

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int n, k;
	cin >> n >> k;
	int ans = k;
	while (--n) ans *= (k - 1);
	cout << ans << '\n';  
	return 0;
}