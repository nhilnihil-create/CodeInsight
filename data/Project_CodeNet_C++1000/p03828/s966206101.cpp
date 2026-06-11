#include <iostream>
#include <iomanip>
#include <algorithm>
#include <bitset>
#include <string>
#include <cmath>
#include <complex>
#include <numeric>
#include <cassert>

#include <vector>
#include <array>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <utility>

#define int64 long long
#define uint64 unsigned long long
using namespace std;

int main()
{
	int64 nn, ans = 1;
	cin >> nn;
	vector<int64> memo(nn + 1, 0);
	for(int64 ii = 2;ii <= nn;ii++)
	{
		int64 tmp = ii;
		for(int64 jj = 2;jj <= ii;jj++)
		{
			while(tmp % jj == 0)
			{
				tmp /= jj;
				memo[jj]++;
			}
		}
	}
	for(int64 ii = 2;ii <= nn;ii++)
	{
		ans *= memo[ii] + 1;
		ans %= 1000000007;
	}
	cout << ans << endl;
	return 0;
}
