#pragma region
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
//#define rep(i, s, e) for (int(i) = (s); (i) < (e); ++(i))
#define rep(i, e) for (int(i) = 0; (i) < (e); ++(i))
#define all(x) x.begin(),x.end()
#pragma endregion


int main()
{
	ll MOD = 1e9 + 7;
	int n; cin >> n;
	string u, d; cin >> u >> d;
	int now;
	ll res;
	bool tate;
	if (u[0] == d[0])
	{
		res = 3;
		now = 1;
		tate = true;
	}
	else
	{
		res = 6;
		now = 2;
		tate = false;
	}
	while (now < n)
	{
		if (tate)
		{
			res *= 2;
			res %= MOD;
			if (u[now] == d[now])++now;
			else
			{
				now += 2;
				tate = false;
			}
		}
		else
		{
			if (u[now] == d[now])
			{
				++now;
				tate = true;
			}
			else
			{
				now += 2;
				res *= 3;
				res %= MOD;
			}
		}
	}
	cout << res << endl;
}