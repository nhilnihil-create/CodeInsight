#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

const int MAXN = 100000 + 100;

int len, n;
vector<int> odd, ans;

int main()
{
	ios::sync_with_stdio(false);
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);

	cin >> len >> n;
	for(int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		(x & 1 ? odd : ans).push_back(x);
	}
	if(odd.size() > 2)
	{
		cout << "Impossible" << endl;
		return 0;
	}
	if(odd.size() >= 1)
		ans.insert(ans.begin(), odd[0]);
	if(odd.size() >= 2)
		ans.insert(ans.end(), odd[1]);
	
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i] << ' ';
	cout << endl;

	if(ans.size() == 1)
		ans.insert(ans.begin(), 0);

	ans.front()++;
	ans.back()--;
	if(!ans.back()) ans.pop_back();
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i] << ' ';
	cout << endl;


	return 0;
}
