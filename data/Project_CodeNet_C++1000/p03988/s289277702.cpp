#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
int n;
int cnt[maxn], Max;
void no() { puts("Impossible"); exit(0);}
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		int v;
		scanf("%d", &v);
		++cnt[v];
		Max = max(Max, v);
	}
	if(Max % 2 == 0)
	{
		int h = Max / 2;
		for(int i = 1; i < h; ++i) if(cnt[i]) no();
		if(cnt[h] != 1) no();
		for(int i = h + 1; i <= Max; ++i) if(cnt[i] < 2) no();
	}
	else
	{
		int h = (Max + 1) / 2;
		for(int i = 1; i < h; ++i) if(cnt[i]) no();
		if(cnt[h] != 2) no();
		for(int i = h + 1; i <= Max; ++i) if(cnt[i] < 2) no();
	}
	puts("Possible");
	return 0;
}
		
	