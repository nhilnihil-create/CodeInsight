#include <bits/stdc++.h>
#define LL long long
#define PB push_back
using namespace std;
const LL mod = 1000 * 1000 * 1000 + 7;
const LL ob = (mod + 1) >> 1;
set<pair<int , int> > ye;
set<pair<int , int> > toCheck;
LL ans[10];
int main()
{
	ios_base::sync_with_stdio(0);
	int h , w , n;
	cin >> h >> w >> n;
	for(int i = 0; i < n; i++)
	{
		int x , y;
		cin >> x >> y;
		ye.insert({x , y});
		for(int i = max(1 , x - 2); i <= min(h - 2 , x); i++)
			for(int j = max(1 , y - 2); j <= min(w - 2 , y); j++)
			{
				toCheck.insert({i , j});
			}
	}
	LL all = (h - 2) * (LL)(w - 2);
	for(auto x : toCheck)
	{
		//cout << x.first << " " << x.second << endl;
		int cnt = 0;
		for(int X = x.first; X <= x.first + 2; X++)	
		{
			for(int Y = x.second; Y <= x.second + 2; Y++)
				cnt += ye.count({X , Y});
		}
		ans[cnt]++;
		all--;
	}
	ans[0] = all;
	for(int i = 0; i < 10; i++)
	{
		cout << ans[i] << endl;
	}
}


