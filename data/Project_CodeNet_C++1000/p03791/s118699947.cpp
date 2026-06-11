
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;
using ll = long long;
const ll MOD = 1000000007;

int n;
int a[114514] = {};

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	ll ans = 1;
	ll keis = 0;
	for (int i = 1; i < n; ++i)
	{
		//keis + 1個配置したい！
		if ((keis + 1) * 2 - 1 <= a[i - 1] )
		{
			keis++;
		}
		ans *= (keis + 1);
		ans %= MOD;
	}
	cout << ans << endl;
	return 0;
}