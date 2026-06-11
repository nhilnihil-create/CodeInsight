#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, ans, ar[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> ar[i];
	
	for (int i = 1; i <= n; i++)
		if (ar[i] == i) {
			swap(ar[i], ar[i + 1]);
			ans++;
		}
	cout << ans;
}