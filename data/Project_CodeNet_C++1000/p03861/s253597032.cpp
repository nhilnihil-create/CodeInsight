#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
const int iINF = 1001001001;
const long long llINF = 1LL << 60;
int main()
{
	ll a, b, n;
	cin >> a >> b >> n;
	ll ans = b / n;
	ans -= (a - 1) / n;
	if (a == 0) {
		ans++;
		if (n == 1)	ans--;
	}
	cout << ans << endl;
	return 0;
}