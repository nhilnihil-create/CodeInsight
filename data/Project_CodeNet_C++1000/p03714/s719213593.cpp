#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long LL;
LL a[300005];
priority_queue<LL, vector<LL>, greater<LL> > q1;
priority_queue<LL> q2;
LL sum1,sum2;
LL ans1[300005], ans2[300005];
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1 ; i <= 3 * n ;i++){
		scanf("%lld", &a[i]);
	}
	sum1 = 0, sum2 = 0;
	for(int i = 1 ; i <= 3 * n ; i++){
		sum1 += a[i];
		ans1[i] = sum1;
		q1.push(a[i]);
		if(q1.size() > n){
			sum1 -= q1.top();
			q1.pop();
			ans1[i] = sum1;
		}
	}
	for(int i = 3 * n ; i >= 1 ; i--){
		sum2 += a[i];
		ans2[i] = sum2;
		q2.push(a[i]);
		if(q2.size() > n){
			sum2 -= q2.top();
			q2.pop();
			ans2[i] = sum2;
		}
	}
	LL ans = -1e18;
	for(int i = n ; i <= 2 * n ; i++){
		ans = max(ans , ans1[i] - ans2[i + 1]);
	}
	printf("%lld\n", ans);
}