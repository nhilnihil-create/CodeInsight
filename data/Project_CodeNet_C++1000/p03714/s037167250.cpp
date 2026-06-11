#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxx = 3e5 + 7;
const int Inf = 1 << 30;
const ll INF = 1ll << 60;
int n;
ll a[maxx];
ll suml[maxx], sumr[maxx];
ll s1, s2;
priority_queue <ll, vector<ll>, less<ll> > qua; //降序, 队头大
priority_queue <ll, vector<ll>, greater<ll> > que; //升序, 队头小

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
	suml[n] = s1; //前n项和
	sumr[n * 2 + 1] = s2; //后n项和
	int l = n + 1, r = 2 * n;
	//只能精确删除n项, 无论怎么删, 后n项都不可能进到前n项去
	//故让中间的n项去往两边置换
	//中间的n项必然是前x个置换到前n项内, 后n-x个置换到后n项内(或者不发生置换)
	//故分别维护前缀和、后缀和, 前缀和与后缀和的差维护一个最大值
	while(l <= r) {
		if(a[l] > que.top()) { //每次置换出最小的队头
			s1 += a[l];
			s1 -= que.top();
			que.pop();
			que.push(a[l]);
		}
		suml[l] = s1; //维护前缀和
		l++;
	}
	l = n + 1, r = 2 * n;
	while(l <= r) {
		if(a[r] < qua.top()) { //每次置换出最大的队头
			s2 += a[r];
			s2 -= qua.top();
			qua.pop();
			qua.push(a[r]);
		}
		sumr[r] = s2; //维护后缀和
		r--;
	}
	ll ans = -INF;
	for(int i = n; i <= n * 2; i++) ans = max(ans, suml[i] - sumr[i + 1]);
	printf("%lld\n", ans);
}