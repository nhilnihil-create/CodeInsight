#include "bits/stdc++.h"
using namespace std;
int a[100000];
int main()
{
	int n, total = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
		--a[i];
	}
	for(int i = 1; i < n; ++i)
	{
		if(a[i - 1] == i - 1 && a[i] == i)
		{
			swap(a[i - 1], a[i]);
			++total;
		}
	}
	for(int i = 1; i < n; ++i)
	{
		if(a[i - 1] == i - 1 || a[i] == i)
		{
			if(a[i - 1] != i && a[i] != i - 1)
			{
				swap(a[i - 1], a[i]);
				++total;
			}
		}
	}
	printf("%d\n", total);
}