#include <bits/stdc++.h>
using namespace std;
#define int long long
deque<int> ans; int tot = 0;
void sol(int x)
{
	if(x == 0) return;
	if(x & 1) sol((x - 1) >> 1LL), ans.push_back(++tot);
	else sol(x - 1), ans.push_front(++tot);
}
signed main()
{
	int n = 0;
	cin >> n;
	sol(n);
	for(int i = 1; i <= tot; i++) ans.push_back(i);
	cout << ans.size() << endl;
	for(auto i:ans) cout << i << " ";
	cout << endl;
	return 0;
}