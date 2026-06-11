#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <iostream>
#include <algorithm>
#include <stack>
#include <cmath>
#include <queue>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
const int MaxN = 3e5 + 5;

priority_queue <LL, vector<LL> , greater<LL> > pre_que;
priority_queue <LL> pos_que;
int a[MaxN];
int n;
LL pre_sum[MaxN], pos_sum[MaxN];

void solve1() {
	LL sum = 0;
	for(int i = 1; i <= 3 * n; i++) {
		pre_que.push(a[i]);
		sum += a[i];
		pre_sum[i] = sum;
		if(pre_que.size() > n) {
			sum -= pre_que.top();
			pre_que.pop();
			pre_sum[i] = sum;
		}
	}
}

void solve2() {
	LL sum = 0;
	for(int i = 3 * n; i >= 1; i--) {
		pos_que.push(a[i]);
		sum += a[i];
		pos_sum[i] = sum;
		if(pos_que.size() > n) {
			sum -= pos_que.top();
			pos_que.pop();
			pos_sum[i] = sum;
		}
	}
}
int main() 
{
	scanf("%d", &n);
	for(int i = 1; i <= 3 * n; i++) scanf("%d", &a[i]);
	solve1();
	solve2();
	LL ans = -1e18;
	for(int i = n; i <= 2 * n; i++)
		ans = max(ans, pre_sum[i] - pos_sum[i + 1]);
	printf("%lld\n", ans);
	return 0;
}
