#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100;

int a[N];
int n, ans;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		if (a[i] == i + 1) {
			ans++;
			swap(a[i], a[i + 1]);	
		}
	return cout << ans, 0;
}
