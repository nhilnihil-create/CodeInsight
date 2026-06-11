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
#define Coutfix(i) cout << fixed << setprecision(i)		//coutの浮動小数出力の桁数設定
using namespace std;

int main()
{
	int64 nn, tmp, ans = 1000000000;
	cin >> nn;
	vector<int64> aa(nn);
	for(int64 ii = 0;ii < nn;ii++)
	{
		cin >> aa[ii];
	}
	for(int64 ii = -100;ii <= 100;ii++)
	{
		tmp = 0;
		for(int64 jj = 0;jj < nn;jj++)
		{
			tmp += (ii - aa[jj]) * (ii - aa[jj]);
		}
		ans = min(ans, tmp);
	}
	cout << ans << endl;
	return 0;
}