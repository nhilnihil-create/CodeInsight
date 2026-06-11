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
const ll Inf = 1 << 30;
const int maxx = 3e5 + 8;

priority_queue <ll> qua;
priority_queue <ll, vector<ll>, greater<ll> > que;
int n;
ll a[maxx];
ll suml[maxx], sumr[maxx];
ll s1, s2;

int main() {

	/*ll ss[6] = {0, 2, 4, 5, 3, 1};
	for(int i = 1; i <= 5; i++) que.push(ss[i]);
	while(!que.empty()) {
		cout << que.top() << endl;
		que.pop(); //1 2 3 4 5
		//qua.pop(); //5 4 3 2 1
	}*/

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
	for(int i = n + 1; i <= n * 2; i++) {
		if(a[i] > que.top()) {
			s1 -= que.top();
			s1 += a[i];
			que.pop();
			que.push(a[i]);
		}
		suml[i] = s1;
	}
	sumr[2 * n + 1] = sumr[2 * n] = s2;
	for(int i = n * 2 - 1; i >= n; i--) {
		if(a[i + 1] < qua.top()) {
			s2 -= qua.top();
			s2 += a[i + 1];
			qua.pop();
			qua.push(a[i + 1]);
		}
		sumr[i] = s2;
	}
	ll ans = -Inf;
	/*for(int i = n + 1; i <= n * 2; i++) {
		cout << suml[i] << " " << sumr[i] << endl;
	}*/
	for(int i = n; i <= n * 2; i++) ans = max(ans, suml[i] - sumr[i]);
	if(ans == -Inf) ans = suml[n] - sumr[n];
	printf("%lld\n", ans);
}