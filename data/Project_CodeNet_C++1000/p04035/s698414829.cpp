#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100010;

int n, d;

int v[MAXN];

vector< int > ans;

int main()
{
	scanf("%d %d",&n,&d);

	for(int i = 1 ; i <= n ; i++)
		scanf("%d",&v[i]);

	int mx = 1;

	for(int i = 2 ; i < n ; i++)
		if( v[mx] + v[mx + 1] < v[i] + v[i + 1] ) mx = i;

	if( v[mx] + v[mx + 1] < d )
	{
		printf("Impossible\n");
		return 0;
	}

	for(int i = 1 ; i < mx ; i++)
		ans.push_back( i );

	for(int i = n - 1 ; i > mx ; i--)
		ans.push_back( i );

	ans.push_back( mx );

	printf("Possible\n");

	for(int i = 0 ; i < ans.size() ; i++)
		printf("%d\n",ans[i]);
}