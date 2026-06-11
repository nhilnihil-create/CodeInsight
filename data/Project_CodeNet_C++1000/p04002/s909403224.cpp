#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define INF (int(1e9)+7)//1e9+7进制
#define maxn (int(1e6)+5)
typedef long long ll;
ll node[maxn];
ll res[15];
int main(void)
{
	ll H, W, N;
	scanf("%lld %lld %lld", &H, &W, &N);
	int cnt = 0;
	while (N--)
	{
		ll a, b;
		scanf("%lld %lld", &a, &b);
		for (int i = -1; i <= 1; i++)
			for (int j = -1; j <= 1; j++)
				if (a + i >= 2 && a + i <= H - 1 && b + j >= 2 && b + j <= W - 1)
					node[cnt++] = (a + i) * INF + (b + j);
	}
	sort(node, node + cnt);
	ll temp = node[0];
	ll sum = 1;
	for (int i = 1; i < cnt; i++) {
		if (node[i] == temp)
			sum++;
		else
			res[sum]++, sum = 1, temp = node[i];
	}
	if(cnt)res[sum]++;
	res[0] = (H - 2) * (W - 2);
	for (int i = 1; i <= 9; i++)
		res[0] -= res[i];
	for (int i = 0; i <= 9; i++)
		printf("%lld\n", res[i]);
	return 0;
}