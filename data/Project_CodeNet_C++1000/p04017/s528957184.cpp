#include<bits/stdc++.h>
using namespace std;
int n, dis, t;
int a[1000010];
int f[1000010][40];

int read()
{
	int x = 0,f = 1;
	char ch= getchar();
	while(ch<'0' || ch>'9')
	{
		if(ch == '-')
			f=-1;
		ch = getchar();
	} 
	while(ch>='0' && ch<='9')
	{
		x = (x<<1) + (x<<3) + ch-'0';
		ch = getchar();
	}
	return x*f;
}

void chu()
{
	for(int i = 1;i <= n;i++)
	{
		int id = upper_bound(a + 1,a + 1 + n, a[i] + dis) - a - 1; 
		//返回第一个比a[i] + l小值 
		if(a[i] + dis > a[n])		
			f[i][0] = n;
		else
			f[i][0] = id;
	} 
	for(int i = 1;i <= 32;i++)
	{
		for(int j = 1;j <= n;j++)
			f[j][i] = f[f[j][i - 1]][i - 1]; 
		// 他走2的i次方天等于他从j走i - 1天，再从该处走i - 1天 
	}
}

int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n = read();
	for(int i = 1;i <= n;i++)
		a[i] = read();
	dis = read(), t = read();
	chu();
	for(int i = 1;i <= t;i++)
	{
		int l = read(), r = read();
		if(l > r)
			swap(l, r);
		int ans = 0;
		for(int j = 30;j >= 0;j --)   //倍增 
		{
			if(f[l][j] < r)
			{
				ans += (1 << j);
				l = f[l][j];
			}
		}
		printf("%d\n", ans + 1);
	}
	return 0;
} 