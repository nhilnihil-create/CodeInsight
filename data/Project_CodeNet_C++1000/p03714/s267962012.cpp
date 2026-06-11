//优先队列
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll Inf = 1e17 + 779;
const int maxx = 3e5 + 8;

priority_queue <ll, vector<ll>, less<ll> > qua; //降序, 队头大
priority_queue <ll, vector<ll>, greater<ll> > que; //升序, 队头小

int n;
ll a[maxx];
ll suml[maxx], sumr[maxx];
ll s1, s2;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n * 3; i++) {
		scanf("%lld", &a[i]);
		if(i <= n) {
			s1 += a[i];
			que.push(a[i]);
		}
		else if(i >= 2 * n + 1) {
			s2 += a[i];
			qua.push(a[i]);
		}
	}
	suml[n] = s1;
	sumr[n * 2 + 1] = s2;
	int l = n + 1, r = 2 * n;
	while(l <= r) {
		if(a[l] > que.top()) {
			s1 += a[l];
			s1 -= que.top();
			que.pop();
			que.push(a[l]);
		}
		suml[l] = s1;
		l++;
	}
	l = n + 1, r = 2 * n;
	while(l <= r) {
		if(a[r] < qua.top()) {
			s2 += a[r];
			s2 -= qua.top();
			qua.pop();
			qua.push(a[r]);
		}
		sumr[r] = s2;
		r--;
	}
	ll ans = -Inf;
	for(int i = n; i <= n * 2; i++) ans = max(ans, suml[i] - sumr[i + 1]);
	printf("%lld\n", ans);
}