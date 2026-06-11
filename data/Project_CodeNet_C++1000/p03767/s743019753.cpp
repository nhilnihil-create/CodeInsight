#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
using ll = long long;

int main() {
	int n;
	
	cin >> n;
	vector<int> a(3*n);
	long long int ans = 0;
	for (int i = 0; i <3* n; i++) {
		cin >> a.at(i);
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++) {
		ans += a.at(3*n - 2 - (2 * i));
	}
	cout << ans << endl;
	return 0;
}
