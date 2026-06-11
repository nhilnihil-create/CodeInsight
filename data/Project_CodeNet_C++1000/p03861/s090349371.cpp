#include <cstdlib>

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
	ll a, b, x, ax, bx, ret;
	cin >> a >> b >> x;

	ret = 0;
	if (a == 0) ret++;

	ax = max((ll)0,(a-1)) / x;
	bx = b / x;
	ret = bx - ax + ret;

	cout << ret << endl;

	return 0;
}