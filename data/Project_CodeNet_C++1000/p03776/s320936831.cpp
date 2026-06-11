#include<stdio.h>
#include<algorithm>
#define ull unsigned long long 
#define ll long long
using namespace std;
bool cmp (ll x, ll y)
{
	return x > y;
}
int main()
{
	int n, a, b;
	ll v[50];
	double ans = 0;
	ull cnt = 0;
	scanf("%d %d %d", &n, &a, &b);
	for(int i = 1; i <= n;i++)
	{
		scanf("%lld", &v[i]);
	}
	sort(v + 1, v + n + 1, cmp);
	if(v[1] == v[a])
	{
		printf("%0.6lf\n",(double)v[1]);
		int x = a;
		while(x <= n && v[1] == v[x])
		{
			x++;	
		}
		x--;
		ull tmp = 1;
		for(int i = 1; i < a; i++)
			tmp = tmp * (x - i + 1) / i;
		if(x >= b)
			for(int i = a; i <= b; i++)
			{
				tmp = tmp * (x - i + 1) / i;
				cnt += tmp;
			}
		else
			for(int i = a; i <= x; i++)
			{
				tmp = tmp * (x - i + 1) / i;
				cnt += tmp;
			}
	}	
	else
	{
		for(int i = 1; i <= a; i++)
			ans += (double)v[i];
		ans /= a;
		printf("%0.6lf\n",ans);
		int l, r;
		for(l = a; v[a] == v[l]; l--);
			l++;
		for(r = a;r <= n && v[a] == v[r]; r++);
			r--;
		int x = a - l + 1;
		int y = r - l + 1;
		cnt = 1;
		for(int i = 1; i <= x; i++)
			cnt = cnt * (y - i + 1) / i;
	}
	printf("%llu \n",cnt);
	return 0;
 } 