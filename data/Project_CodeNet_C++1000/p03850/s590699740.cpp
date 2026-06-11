#include <stdio.h>
#include <iostream>
#include <vector>
#include <assert.h>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <sstream>
#include <memory.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
typedef long long ll;
int n;
vector<int> v;
vector<char> op;
ll dp[100000][3];
ll calc(int i, int o) {
	if (o == 3)
		return -1e18;
	if (i == n)
		return 0;
	ll &ret = dp[i][o];
	if (ret != -1)
		return ret;
	ret = calc(i + 1, o) + v[i] * (o & 1 ? -1 : 1);
	if (o)
		ret = max(ret, calc(i, o - 1));
	if (v[i] < 0)
		ret = max(ret, calc(i + 1, o + 1) + v[i] * (o & 1 ? -1 : 1));
	return ret;
}
int main()
{
	cin >> n;
	v.resize(n);
	op.resize(n - 1);
	cin >> v[0];
	for (int i = 1; i < n; ++i) {
		cin >> op[i - 1] >> v[i];
		v[i] *= op[i - 1] == '+' ? 1 : -1;
	}
	memset(dp, -1, sizeof(dp));
	cout << calc(1, 0) + v[0] << endl;
	return 0;
}