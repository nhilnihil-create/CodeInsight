#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;

ll n, m, x, y, sum, mx, a[100005], s[200005];
int main() {
	ll i;
	cin >> n >> m;
	for(i=1; i<=n; i++) scanf("%lld", &a[i]);
	for(i=1; i<n; i++) {
		x = a[i]; y = a[i+1];
		if(x > y) y += m;
		sum += y-x;
		if(y-x <= 1) continue;
		s[x+2]++;
		s[y+1] -= y-x;
		s[y+2] += y-x-1;
	}
	for(i=1; i<2*m+1; i++) s[i] += s[i-1];
	for(i=1; i<2*m+1; i++) s[i] += s[i-1];
	for(i=1; i<=m; i++) mx = max(mx, s[i] + s[i+m]);
	cout << sum - mx;
	return 0;
}