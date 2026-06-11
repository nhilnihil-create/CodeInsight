#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n, a[maxn];
bool calc()
{
	int odd = 0;
	bool one = 0;
	for(int i = 1; i <= n; ++i) 
	{
		if(a[i] == 1) one = 1;
		if(a[i] & 1) ++odd;
	}
	if(odd > 1 || one) return !(odd & 1);
	int d = 0;
	for(int i = 1; i <= n; ++i) 
	{
		if(a[i] & 1) --a[i];
		d = __gcd(d, a[i]);
	}
	for(int i = 1; i <= n; ++i) a[i] /= d;
	return !calc();
}
int main()
{
	scanf("%d", &n);
	if(!(n & 1))
	{ 
		bool cnt = 0;
		for(int i = 1; i <= n; ++i)
		{
			scanf("%d", &a[i]);
			if(!(a[i] & 1)) cnt ^= 1;
		}
		if(cnt) puts("First");
		else puts("Second");
	}
	else
	{
		for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
		if(calc()) puts("First");
		else puts("Second");
	}
	return 0;
}