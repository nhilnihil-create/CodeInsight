#include<iostream>
#include<map>
#include<vector>
#define ll long long
using namespace std;
map< pair<int, int>, int> mp;
int h, w;
int n;
int a, b;
ll ans[10];
int main()
{
	ios::sync_with_stdio(false);
	cin >> h >> w >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		for (int i = a - 2; i <= a; i++)
			for (int j = b - 2; j <= b; j++)
				if (i > 0 && j > 0 && i + 2 <= h && j + 2 <= w)
					mp[make_pair(i, j)]++;
	}
	for (map< pair<int, int>, int>::iterator i = mp.begin(); i != mp.end(); i++)
		ans[i->second]++;
	ans[0] = 1ll * (h - 2) * (w - 2);
	for (int i = 1; i <= 9; i++)
		ans[0] -= ans[i];
	for (int i = 0; i < 10; i++)
		cout << ans[i] << endl;
	return 0;
}