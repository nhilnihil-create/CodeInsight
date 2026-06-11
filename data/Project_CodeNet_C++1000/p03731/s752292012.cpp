#include <bits/stdc++.h>

using namespace std;

#define intt long long 
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N = 200005;

int n, t;
int a[N];

int main() {

	FAST;

	cin >> n >> t;
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	intt ans = 0;
	for (int i = 0; i < n; i ++) {
		if (a[i] - a[i - 1] > t) {
			ans += t;
		}
		else {
			ans += (a[i] - a[i - 1]);
		}
	}
	ans += t;
	cout << ans << '\n';
	return 0;
}