#include <cstdio> 
#include <cstring>
#include <algorithm>
using namespace std;
#define LL long long
int n, num[100005], opt[100005];
LL sum[100005], now[100005], ans;
int main()
{
	char ch[2];
	scanf("%d%d", &n, &num[1]); opt[1] = 1;
	now[1] = sum[1] = num[1];
	for(int i = 2; i <= n; i++)
	{
		scanf("%s%d", ch, &num[i]); opt[i] = (ch[0] == '+') ? 1 : -1;
		now[i] = now[i-1] + opt[i] * num[i];
		sum[i] = sum[i-1] + num[i];
	}
	ans = now[n];
	int last = -1;
	for(int i = 1; i <= n; i++) if(opt[i] == -1)
	{
		if(last != -1)
			ans = max(ans, now[last-1] - (sum[i-1] - sum[last-1]) + (sum[n] - sum[i-1]));
		last = i;
	}
	printf("%lld\n", ans);
}
 

