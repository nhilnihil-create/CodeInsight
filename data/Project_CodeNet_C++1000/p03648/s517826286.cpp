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
	ll k; cin >> k;
	cout << 50 << endl;
	vector<ll> a(50, 49);
	rep(i, 50)a[i] += k / 50;
	k %= 50;
	rep(i, k)
	{
		rep(j, 50)
		{
			if (i == j)a[j] += 50;
			else --a[j];
		}
	}
	rep(i, 50)cout << a[i] << endl;
}