#include <bits/stdc++.h>
using namespace std;

const int md = 1000000007;
 	
int main() 
{
	int n;
	scanf("%d", &n);
	int ans = 1;
	for (int i = 0; i < n; i ++) 
	{
		int x;
		scanf("%d", &x);
		if (x <= 2 * i) 
		{
			ans = (long long) ans * (i + 1) % md;
			n --;
			i --;
		}
	}
	for (int i = 1; i <= n; i++) 
		ans = (long long) ans * i % md;
	printf("%d\n", ans);
	return 0;
}