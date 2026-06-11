#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <map>
#include <queue>
#include <set>
#define rep(i,n) for(int i = 0; i < n; i++)
#define rep1(i,n) for(int i = 1; i <= n; i++)
#define co(x) cout << x <<endl
#define cs(x) cout << x <<" "
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
using namespace std;
ll mod = 1e9 + 7;

int main()
{
	string s;
	cin >> s;
	int g_cnt = 0;
	int point = 0;
	rep(i, s.size())
	{
		char opp_hand = s[i];
		if (g_cnt>0)
		{
			if (opp_hand=='g')
			{
				point++;
				g_cnt--;
			}
			else
			{
				g_cnt--;
			}
		}
		else
		{
			if (opp_hand == 'g')
			{
				g_cnt++;
			}
			else
			{
				point--;
				g_cnt++;
			}
		}
	}
	co(point);
	return 0;
}
