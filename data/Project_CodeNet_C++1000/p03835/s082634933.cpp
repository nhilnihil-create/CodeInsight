#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int k, s;
	cin >> k >> s;
	int ans = 0;
	for (int i=0; i<=k; i++) {
		for (int j=0; j<=k; j++) {
			if (s-i-j >= 0 && s-i-j <= k) ans++;
		}
	}
	cout << ans;
}