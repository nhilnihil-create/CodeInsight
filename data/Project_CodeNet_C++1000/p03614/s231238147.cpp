#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn], cnt, n;
bool vis[maxn];
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) 
	{
		scanf("%d", &a[i]); 
		if(a[i] == i) vis[i] = 1;
	}
	for(int i = 1; i <= n; ++i)
	{
		if(!vis[i]) continue;
		int r = i;
		while(r <= n && vis[r]) ++r;
		cnt += (r - i + 1) / 2;
		i = r - 1;
	}
	cout << cnt << endl;
	return 0;
}