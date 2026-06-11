#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n;
int a[maxn];
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1, greater<int>());
	int x, y;
	for(x = 1; x <= a[x]; ++x);
	--x;
	int sg1 = (a[x] - x + 1) & 1;
	for(y = x; x <= a[y]; ++y);
	--y;
	int sg2 = (y - x + 1) & 1;
	if(sg1 && sg2)
		puts("Second");
	else
		puts("First");
	return 0;
}
	 