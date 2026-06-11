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
	vector<ll> a(n), s(n + 1); rep(i, n)cin >> a[i];
	sort(all(a));
	rep(i, n)s[i + 1] = s[i] + a[i];
	int res = 1;
	rrep(i, n)
	{
		if (s[i] * 2 >= a[i])++res;
		else break;
	}
	cout << res << endl;
}