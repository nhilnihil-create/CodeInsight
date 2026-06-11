#include<bits/stdc++.h>
using namespace std;
const int N(111111);
long long dp[N][3];
char st[N], s[N];
int a[N];
int main() {
	int n;
	scanf("%d", &n);
	for(int i(0); i < n; i++) {
		if(i) {
			scanf("%s", st);
			s[i] = st[0];
		}else {
			s[i] = '+';
		}
		scanf("%d", &a[i]);
		if(s[i] == '-')
			a[i] = -a[i];
	}
	for(int i(0); i < n; i++) {
		for(int j(0); j <= 2; j++) {
			dp[i][j] = -1e18;
		}
	}
	dp[0][0] = a[0];
	for(int i(1); i < n; i++) {
		for(int j(0); j <= 2; j++) {
			for(int k(0); k <= j + 1; k++) {
				if(s[i] == '+' && k > j) 
					continue;
				dp[i][k] = max(dp[i][k], dp[i - 1][j] + a[i] * (j % 2 == 0 ? 1 : -1));
			}
		}
	}
	cout << dp[n - 1][0] << endl;
}
