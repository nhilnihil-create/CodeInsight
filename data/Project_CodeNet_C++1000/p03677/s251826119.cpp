#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
vector<int>qs[110000];
int d[110000];
int main()
{
	int num, gen;
	scanf("%d%d", &num, &gen);
	ll now = 0;
	int cnt = 0;
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &d[i]);
		d[i]--;
		if (i != 0)
		{
			if (d[i - 1] < d[i])now += d[i] - d[i - 1];
			else
			{
				now += d[i] + 1;
				cnt++;
				qs[d[i]].push_back(i);
			}
		}
	}
	ll mini = now;
	for (int i = 0; i < gen; i++)
	{
		mini = min(mini, now);
		//printf("%d %lld %d\n", i, now, cnt);
		if (d[0] == i)cnt++, now++, qs[d[1]].push_back(1);
		for (int j = 0; j < qs[i].size(); j++)
		{
			if (qs[i][j] == num - 1)cnt--;
			else now++, qs[d[qs[i][j] + 1]].push_back(qs[i][j] + 1);
			now--;
			now += (d[qs[i][j]] + gen - d[qs[i][j] - 1]) % gen;
		}
		now -= cnt;
	}
	printf("%lld\n", mini);
}