#include <bits/stdc++.h>
using namespace std;

int n;
int x[100001];

int atleast[100010];

const int mod = 1000000007;

int main()
{
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; i++)
		scanf("%d" , &x[i]);
	int cnt = 0;
	for(int i = 1 ; i <= n ; i++)
	{
		int space = x[i] - 1;
		int check = i - 1;
		
		atleast[i] = cnt + 1;
		if(2 * (i - cnt) - 1 > x[i])cnt++;
		//printf("atleast[%d] = %d\n" , i , atleast[i]);
	}

	sort(atleast + 1 , atleast + n + 1);
	int ans = 1;

	cnt = 0;
	for(int i = n ; i >= 1 ; i--)
	{
		if(n - atleast[i] + 1 < cnt)ans = 0;
		else
		{
			ans = (long long)ans * (n - atleast[i] + 1 - cnt) % mod;
		}
		cnt++;
	}
	printf("%d\n" , ans);
	return 0;
}
