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
	int n, m; cin >> n >> m;
	vector<int> v(n);
	rep(i, m)
	{
		int a, b; cin >> a >> b;
		--a, --b;
		++v[a], ++v[b];
	}
	bool ok = true;
	rep(i, n)if (v[i] % 2 != 0)ok = false;
	if (ok)cout << "YES" << endl;
	else cout << "NO" << endl;
}