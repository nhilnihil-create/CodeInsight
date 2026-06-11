#include <bits/stdc++.h>

using namespace std;

const int MAXN = 20010;

int n;

int v[MAXN];
int a[MAXN];
int b[MAXN];
int lazy[MAXN];

int main()
{
	scanf("%d",&n);

	for(int i = 1 ; i <= n ; i++)
		scanf("%d",&v[i]);

	for(int i = 1 ; i <= n ; i++)
	{
		a[i] = i;
		b[i] = n - i + 1;
	}

	for(int i = 1 ; i <= n ; i++)
		lazy[ v[i] ] = i;

	int sum = 0;

	for(int i = 1 ; i <= n ; i++)
	{
		sum += lazy[i];
		a[i] += sum;
	}

	sum = 0;

	for(int i = n ; i > 0 ; i--)
	{
		sum += lazy[i];
		b[i] += sum;
	}

	for(int i = 1 ; i <= n ; i++)
		printf("%d ",a[i]);

	printf("\n");

	for(int i = 1 ; i <= n ; i++)
		printf("%d ",b[i]);
}