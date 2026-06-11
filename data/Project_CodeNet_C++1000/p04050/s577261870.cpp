#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;


const int N = 100010;


int a[N], b[N];

int num[N];


int main()
{
	int n, m;
	
	scanf("%d %d", &n, &m);
	
	int sum = 0;
	
	for (int i = 1; i <= m; i++)
		scanf("%d", &num[i]),
		sum += (num[i] & 1);
	
	if (m == 1)
	{
		if (num[1] == 1)
			puts("1\n1\n1");
		else
			printf("%d \n2 \n%d %d\n", num[1], num[1] - 1, 1);
		return 0;
	}
	if (sum > 2)
		puts("Impossible");
	else
	{
		for (int i = 2; i <= m; i++)
			if (num[i] & 1)
			{
				if (num[1] & 1) swap(num[m], num[i]);
				else swap(num[i], num[1]);
			}
		for (int i = 1; i <= m; i++)
			a[i] = num[i];
		int total = 0;
		if (num[1] > 1) b[++total] = num[1] - 1;
		for (int i = 2; i < m; i++)
			b[++total] = num[i];
		b[++total] = num[m] + 1;
		for (int i = 1; i <= m; i++)
			printf("%d ", a[i]);
		puts("");
		printf("%d\n", total);
		for (int i = 1; i <= total; i++)
			printf("%d ", b[i]);
	}
	
	return 0;
}