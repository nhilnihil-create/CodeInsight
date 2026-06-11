#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100010;

int n, m;

int v[MAXN];

int main()
{
	scanf("%d %d",&n,&m);

	for(int i = 1 ; i <= m ; i++)
	{
		int U, V;
		scanf("%d %d",&U,&V);

		v[U] ^= 1;
		v[V] ^= 1;
	}

	int sum = 0;

	for(int i = 1 ; i <= n ; i++)
		sum += v[i];

	if( sum == 0 ) printf("YES\n");
	else printf("NO\n");
}