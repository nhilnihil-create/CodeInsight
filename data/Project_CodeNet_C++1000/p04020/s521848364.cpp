#pragma region
#define _USE_MATH_DEFINES
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
#include <iomanip>
#include <cstdint>
#include <cstdlib>

using namespace std;
typedef long long ll;
//#define rep(i, s, e) for (int(i) = (s); (i) < (e); ++(i))
#define rep(i, e) for (int(i) = 0; (i) < (e); ++(i))
#define rrep(i, s) for (int(i) = (s) - 1; (i) >= 0; --(i))
#define all(x) x.begin(),x.end()
#pragma endregion


int main()
{
	int n; cin >> n;
	vector<int> a(n); rep(i, n)cin >> a[i];
	ll res = 0;
	rep(i, n - 1)
	{
		if (a[i] % 2 == 1 && a[i + 1] > 0)
		{
			--a[i];
			--a[i + 1];
			++res;
		}
	}
	rep(i, n)res += a[i] / 2;
	cout << res << endl;
}