#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
#include<numeric>
#include<climits>
#include<queue>
 
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<vector<long long>> a(n,vector<long long>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			bool b = true;
			for (int k = 0; k < n; k++) {
				if (k == i || k == j)continue;
				if (a[i][k] + a[j][k] < a[i][j]) {
					cout << -1 << endl;
					return 0;
				}
				if (a[i][k] + a[j][k] == a[i][j]) {
					b = false;
				}
			}
			if (b) ans += a[i][j];
		}
	}

	cout << ans << endl;
	return 0;
}