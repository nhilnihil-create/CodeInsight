#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 100005, inf = 1e18;

ll n, a[N], dt[N][3];

int main()
{
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++) {
		char T[2];
		if(i>1) scanf("%s",T);
		scanf("%lld",&a[i]);
		if(i>1 && T[0] == '-') a[i] *= -1;
	}
	dt[1][0] = a[1];
	dt[1][1] = dt[1][2] = -inf;
	for(ll i=2;i<=n;i++) {
		dt[i][0] = dt[i-1][0] + a[i];
		dt[i][2] = dt[i-1][2] + a[i];
		dt[i][1] = max(dt[i][2], dt[i-1][1] - a[i]);
		if(a[i] < 0) {
			dt[i][2] = max(dt[i][1], dt[i][2]);
			dt[i][1] = max(dt[i][0], dt[i][1]);
		}
	}
	printf("%lld\n",max({dt[n][0], dt[n][1], dt[n][2]}));
}
