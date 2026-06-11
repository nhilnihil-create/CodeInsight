//#pragma GCC optimize("trapv")
#include <iostream>
#include <vector>
#include <tuple>
#include <deque>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cassert>
#include <iomanip>
#include <algorithm>
#include <unordered_set>
#define int long long
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()

using namespace std;

const int MOD = 1e9 + 7;
const int INF = 1e9 * 1e9 + 10;

void fast()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

signed main()
{
	fast();
	int n, k;
	cin >> n >> k;
	vector <int> a(n);
	for (int & e : a)
		cin >> e;
	vector <int> suf(n);
	suf[n - 1] = max(0ll, a[n - 1]);
	for (int i = n - 2; i >= 0; --i)
	{
		suf[i] = suf[i + 1] + max(a[i], 0ll);
	}

	int pref = 0, sum = 0;
	for (int i = 0; i < k; ++i)
	{
		sum += a[i];
	}
	int sufk = 0;
	if (k < n)
		sufk = suf[k];
	int ans = max(sum + sufk, 0ll);
	for (int i = k; i < n; ++i)
	{
		int sufi = 0;
		if (i + 1 < n)
			sufi = suf[i + 1];
		pref += max(a[i - k], 0ll);
		sum -= a[i - k];
		sum += a[i];
		ans = max(ans, pref + max(sum, 0ll) + sufi);
	}
	cout << ans << '\n';
	return 0;
}
