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
	int64 nn, cc, kk;
	cin >> nn >> cc >> kk;
	vector<int64> aa(nn);
	for(int64 ii = 0;ii < nn;ii++)
	{
		cin >> aa[ii];
	}
	sort(aa.begin(), aa.end());
	int64 tmp, old = -1, cnt, ans = 0;
	for(int64 ii = 0;ii < nn;ii++)
	{
		tmp = aa[ii];
		if(old == -1)
		{
			ans++;
			old = tmp;
			cnt = 1;
			continue;
		}
		if(old + kk < tmp)
		{
			ans++;
			old = tmp;
			cnt = 1;
			continue;
		}
		if(cnt == cc)
		{
			ans++;
			old = tmp;
			cnt = 1;
			continue;
		}
		cnt++;
	}
	cout << ans << endl;
	return 0;
}
