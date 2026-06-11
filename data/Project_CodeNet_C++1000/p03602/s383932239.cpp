#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll dist[333][333];
bool f[333][333];
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)for (int j = 0; j < num; j++)scanf("%lld", &dist[i][j]);
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			for (int k = 0; k < num; k++)
			{
				if (dist[j][i] + dist[i][k] < dist[j][k])
				{
					printf("-1\n");
					return 0;
				}
				if (dist[j][i] + dist[i][k] == dist[j][k] && j != i&&i != k)f[j][k] = true;
			}
		}
	}
	ll sum = 0;
	for (int i = 0; i < num; i++)for (int j = 0; j < num; j++)if (!f[i][j])sum += dist[i][j];
	printf("%lld\n", sum / 2);
}