#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n, T, ans;
int a[maxn];
set<int> s;
int main()
{
	cin >> n >> T;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	int Min = a[1], Max = 0;
	for(int i = 1; i <= n; ++i)
	{
		Max = max(Max, a[i] - Min);
		Min = min(Min, a[i]);
	}
	for(int i = 1; i <= n; ++i)
	{
		if(s.find(a[i] - Max) != s.end())
			++ans;
		s.insert(a[i]);
	}
	cout << ans << endl;
	return 0;
}