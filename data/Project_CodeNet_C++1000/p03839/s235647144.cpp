#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int n, k, a[N];
ll pre[N], suf[N], sum, ans;
int main()
{
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++){
		pre[i] = pre[i - 1];
		if(a[i] > 0)
			pre[i] += a[i];
	}
	for(int i = n; i >= 1; i--){
		suf[i] = suf[i + 1];
		if(a[i] > 0)
			suf[i] += a[i];
	}
	for(int i = 1, j = 1; i + k - 1 <= n; i++){
		while(j <= i + k - 1)
			sum += a[j], j++;	
		ans = max(ans, pre[i - 1] + suf[i + k] + max(0ll, sum));
		sum -= a[i];
	}
	printf("%lld", ans);
	return 0;
}
