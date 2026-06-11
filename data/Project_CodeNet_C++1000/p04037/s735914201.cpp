#include <iostream>
#include <cstdio>
#include <algorithm>
#define MN 101000

int n, a[MN];
int q[MN], t = 0;

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	std::sort(a + 1, a + n + 1);
	int s = 0;
	for(int i = 2; i <= n; i++)
	{
		if(a[i] == a[i - 1]) {s ^= 1; continue;}
		if(s == 0)
		{
			if(~(a[i] - a[i - 1]) & 1)
				q[++t] = a[i - 1] + i;
		}
		else
		{
			if((a[i] - a[i - 1]) & 1)
				q[++t] = a[i - 1] - 1 + i;
		}
		s = 0;
	}
	bool ok = 0;
	for(int i = 1; i <= t; i++)
	{
		if(q[i] > n)
		{
			ok = 1; 
			if((q[i] - n) & 1) puts("First");
			else puts("Second"); 
			break;
		}
	}
	if(!ok)
	{
		if(s ^ 1 ^ (a[n] & 1)) puts("First");
		else puts("Second"); 
	}
}