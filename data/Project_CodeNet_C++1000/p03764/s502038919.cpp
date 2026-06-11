#include <bits/stdc++.h>
using namespace std;

#define mk make_pair

const int MAXN = 112345;
const double PI = atan(1) * 4;
const int MOD = 1e9 + 7;

long long x[MAXN], y[MAXN];

int main() {

	int n, m;
	scanf("%d %d", &n, &m);
	
	for(int i = 0; i < n; i++)
		scanf("%lld", &x[i]);
		
	for(int i = 0; i < m; i++)
		scanf("%lld", &y[i]);
		
	long long totalx = 0, totaly = 0;
	
	long long a = 0, b = n - 1LL;
	for(int i = 0; i < n; i++) {
		
		long long temp = ((a * x[i]) % MOD - (b * x[i]) % MOD) % MOD;
		if(temp < 0LL) temp += MOD;
		totalx = (totalx + temp) % MOD;
		
		a++, b--;		
	}
	
	a = 0, b = m - 1LL;
	for(int i = 0; i < m; i++) {
		
		long long temp = ((a * y[i]) % MOD - (b * y[i]) % MOD) % MOD;
		if(temp < 0LL) temp += MOD;
		totaly = (totaly + temp) % MOD;
		
		a++, b--;		
	}
	
	long long ans = (totalx * totaly) % MOD;
	
	cout << ans << "\n";

    return 0;
}
