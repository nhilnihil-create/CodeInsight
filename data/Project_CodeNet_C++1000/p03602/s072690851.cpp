#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll a[303][303];
int ck[303][303];
int main() {
	scanf("%d", &n);
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			//ans += a[i][j];
		}
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][k] + a[k][j] < a[i][j]) {
					puts("-1"); return 0;
				}
				if (i == k || j == k)continue;
				if (a[i][k] + a[k][j] == a[i][j]) {
					//ans -= a[i][j];
					ck[i][j] = 1;
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (!ck[i][j])ans += a[i][j];
	cout << ans / 2;
}