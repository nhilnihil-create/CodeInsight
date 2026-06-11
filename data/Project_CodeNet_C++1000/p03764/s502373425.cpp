#include <bits/stdc++.h>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define mod 1000000007
#define N 1000005
using namespace std;

typedef long long ll;

ll n, m, crp, ans, a[N], b[N];

int main() {
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	scanf("%lld %lld",&n ,&m);
	for(int i = 1; i <= n; i++)
		scanf("%lld",a + i);
	for(int i = 1; i <= m; i++)
		scanf("%lld",b + i);
	for(int i = 1; i < n; i++)
		crp = (crp + ((a[i + 1] - a[i])*i%mod)*(n - i)%mod)%mod;
	for(int i = 1; i < m; i++)
		ans = (ans + (((b[i + 1] - b[i])*crp%mod)*i%mod)*(m - i)%mod)%mod;
	printf("%lld\n", ans);
	return 0;
}