#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100010;
const int INF = 1000000010;

int n, t;

int v[MAXN];

int main()
{
	scanf("%d %d",&n,&t);

	for(int i = 1 ; i <= n ; i++)
		scanf("%d",&v[i]);

	int mn = INF;
	int profit = -INF;

	for(int i = 1 ; i <= n ; i++)
	{
		profit = max( profit , v[i] - mn );
		mn = min( mn , v[i] );
	}

	int ans = 0;

	mn = INF;

	for(int i = 1 ; i <= n ; i++)
	{
		int s = 0;

		if( v[i] - mn == profit )
		{
			s = 1;
			ans++;
		}

		mn = min( mn , v[i] ) + s;
	}

	printf("%d\n",ans);
}