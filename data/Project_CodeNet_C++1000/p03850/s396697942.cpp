
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
#include <list>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <array>
#include <cassert>
#include <bitset>
using namespace std;
using LL = long long;

int n;
LL a[114514];
bool p[114514];//true=+ false=-

const LL INF = 1e17;

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		if (i != 0)
		{
			char c;
			cin >> c;
			p[i] = (c == '+');
		}
		cin >> a[i];
	}
	p[0] = true;
	LL dp[4], ndp[4];
	dp[0] = 0;
	dp[1] = dp[2] = dp[3] = -INF;
	for (int i = 0; i < n; ++i)
	{
		fill(ndp, ndp + 4, -INF);
		for (int j = 0; j <= 2; ++j)
		{
			int jj = j + (!p[i]);
			bool neg = jj % 2;
			LL val = -114514;
			if (!p[i])
			{
				val = -a[i];
				if (!neg)val = -val;
			}
			else
			{
				val = a[i];
				if (neg)val = -val;
			}
			ndp[jj] = dp[j] + val;
		}
		//括弧を閉じる
		for (int j = 3; j >= 1; --j)
		{
			ndp[j - 1] = max(ndp[j - 1], ndp[j]);
		}
		copy(ndp, ndp + 4, dp);
	}
	cout << dp[0] << endl;
	return 0;
}
