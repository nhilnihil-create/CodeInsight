#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n, cnt1, cnt2;
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) 
	{
		int v;
		scanf("%d", &v);
		if(v & 1) ++cnt1;
		else ++cnt2;
	}
	if(cnt1 & 1) puts("NO");
	else puts("YES");
	return 0;
}
		