#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<functional>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
#include<cmath>
#include<set>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
bool d[12][12];
int main() {
	ll N, K, ans = 1e13;
	scanf("%lld%lld", &N, &K);
	vector<ll> h(N);
	rep(i, 0, N)scanf("%d", &h[i]);
	rep(i, 0, 1 << N) {
		ll cost = 0, c = 0, m = 0;
		rep(i2, 0, N) {
			if (i & (1 << i2)) {
				c++;
				if (m >= h[i2]) {
					cost += ++m - h[i2];
				}
				else m = h[i2];
			}
			else if (m < h[i2])m = h[i2], c++;
		}
		if(c == K)ans = min(ans, cost);
	}
	printf("%lld\n", ans);
	return 0;
}