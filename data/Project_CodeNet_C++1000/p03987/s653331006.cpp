#include <iostream>
#include <cstdio>
using namespace std;

typedef long long LL;
const int N = 2e5 + 100;
struct Stack {
	int sep, idx;
};

Stack stk[N];
int n, top, a[N];
LL preSum, ans;

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
	}
	for(int i = 1; i <= n; i ++ ) {
		int x = 0;
		while ( a[ stk[ top].idx] > a[i]) {
			x += stk[top].sep;
			preSum -= (LL)stk[top].sep * a[ stk[top].idx];
			top --;
		}
		stk[ ++ top].idx = i, stk[top].sep = x + 1;
		preSum += (LL)stk[top].sep * a[ stk[top].idx];
		ans += preSum;
	}
	printf("%lld\n", ans);
	return 0;
}