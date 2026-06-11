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

#define PI 3.14159265358979323846
#define int64 long long
#define uint64 unsigned long long
#define coutfix(i) cout << fixed << setprecision(i)		//coutの浮動小数出力の桁数設定
using namespace std;

int main()
{
	int64 nn;
	cin >> nn;
	vector<int64> aa(nn);
	for(int64 ii = 0;ii < nn;ii++)
	{
		cin >> aa[ii];
	}
	sort(aa.begin(), aa.end());
	int64 ans = 0, sum = 0;
	for(int64 ii = 0;ii < nn - 1;ii++)
	{
		sum += aa[ii];
		if(aa[ii + 1] <= 2 * sum)
		{
			ans++;
		}
		else
		{
			ans = 0;
		}
	}
	if(aa[nn - 1] > sum * 2)
	{
		cout << 1 << endl;
	}
	else
	{
		cout << ans + 1 << endl;
	}
	return 0;
}