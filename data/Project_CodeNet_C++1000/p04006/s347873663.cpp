#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 2005;

int n, a[N], x, a2[N];

int main(){
	scanf("%d%d", &n, &x);
	for(int i = 0;i < n;i++)
		scanf("%d", a + i);
	ll sol = (ll)1e18;
	for(int k = 0;k <= n;k++){
		ll cur = (ll)x * k;
		for(int i = 0;i < n;i++)
			cur += a[i];
		sol = min(sol, cur);
		for(int i = 0;i < n;i++)
			a2[i] = min(a[i], a[(i + 1) % n]);
		for(int i = 0;i < n;i++)
			a[i] = a2[i];
	}
	printf("%lld\n", sol);
}