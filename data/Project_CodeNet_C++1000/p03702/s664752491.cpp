#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<set>
#include<queue>
#include<string>
#include<sstream>
#include<iostream>
#include<sstream>
#include<stack>
#include<map>
#include<vector>
using namespace std;
long long c[110000];
long long  n, a, b;

bool ok(long long s)
{
	long long  sum = 0;
	long long num = s * b;
	for (long long  i = 0; i < n; i++)
	{
		long long  ttt = c[i] - num;
		if (ttt > 0)
		{
			if (ttt % (a-b) != 0)sum += (ttt / (a-b) )+ 1;
			else sum +=ttt / (a-b);
			if (sum > s)return false;
		}
	}
	return true;
}
int main()
{
	int i, j;
	scanf("%lld %lld %lld", &n, &a, &b);
	for (i = 0; i < n; i++)
	{
		scanf("%lld", &c[i]);
	}
	long long  ans=0, l=0, r=1999999999;
	while (l <= r)
	{
		long long  mid = (l + r) / 2;
		if (ok(mid))ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	printf("%lld", ans);
}