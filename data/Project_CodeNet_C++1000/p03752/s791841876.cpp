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
#define rrep(i, s) for (int(i) = (s) - 1; (i) >= 0; --(i))
#define all(x) x.begin(),x.end()
#pragma endregion


int main()
{
	int n, k; cin >> n >> k;
	vector<ll> a(n); rep(i, n)cin >> a[i];
	ll res = 1e18;
	rep(i, pow(2, n - 1))
	{
		ll tmp = 0;
		ll now = a[0];
		int cnt = 1;
		rep(j, n - 1)
		{
			if (i&(1 << j))
			{
				++cnt;
				if (now < a[j + 1])now = a[j + 1];
				else
				{
					tmp += now - a[j + 1] + 1;
					++now;
				}
			}
			else
			{
				now = max(now, a[j + 1]);
			}
		}
		if (cnt >= k)res = min(res, tmp);
	}
	cout << res << endl;
}