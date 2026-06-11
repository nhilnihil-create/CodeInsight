#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue> 
#include <stack>
#include <set>
#include <list>

using namespace std;
typedef long long ll;
#define rep(i, s, e) for (int(i) = (s); (i) <= (e); ++(i))
#define all(x) x.begin(),x.end()


int main()
{
	int h, w, n; cin >> h >> w >> n;
	vector<int> a(n); rep(i, 0, n - 1)cin >> a[i];
	vector<int> b;
	rep(i, 0, n - 1)
	{
		rep(j, 1, a[i])
		{
			b.push_back(i + 1);
		}
	}
	vector<vector<int>> ans(h, vector<int>(w));
	int cnt = 0;
	rep(i, 0, h - 1)
	{
		rep(j, 0, w - 1)
		{
			int x;
			if (i % 2 == 0)x = j;
			else x = w - 1 - j;
			ans[i][x] = b[cnt];
			++cnt;
		}
	}
	rep(i, 0, h - 1)
	{
		rep(j, 0, w - 1)
		{
			cout << ans[i][j] << " ";
		}
		cout << "" << endl;
	}
}
