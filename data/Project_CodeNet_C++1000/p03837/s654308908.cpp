#include<iostream>
#include<string.h>
#include<algorithm>
#include<stdio.h>
#include<math.h>
#include<vector>
#include<map>
#include<set>
#define debug(a) cout << "*" << a << "*" << endl
using namespace std;
typedef long long ll;
typedef pair<int, int> node;
typedef pair<node, int> P;
int n, m, mp[105][105];
const int inf = 0x3f3f3f3f;
vector<P> vec;
int main()
{	
	while (~scanf("%d%d", &n, &m))
	{
		int ans = 0;
		memset(mp, inf, sizeof(mp));
		for (int i = 0; i < m; i++)
		{
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			mp[a][b] = c;
			mp[b][a] = c;
			vec.push_back(P(node(a, b), c));
		}
		for (int k = 1; k <= n; k++)
		{
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= n; j++)
				{
					mp[i][j] = min(mp[i][k] + mp[k][j], mp[i][j]);
				}
			}
		}
		for (int i = 0; i < m; i++)
		{
			//debug(mp[(vec[i].first).first][(vec[i].first).second]);
			if (mp[(vec[i].first).first][(vec[i].first).second] < vec[i].second)	ans++;
		}
		printf("%d\n", ans);
	}
}