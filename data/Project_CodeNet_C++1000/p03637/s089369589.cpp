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
	int64 nn, m4 = 0, m2 = 0, ot = 0;
	cin >> nn;
	vector<int64> aa(nn);
	for(int64 ii = 0;ii < nn;ii++)
	{
		cin >> aa[ii];
		if(aa[ii] % 4 == 0)
		{
			m4++;
		}
		else if(aa[ii] % 2 == 0)
		{
			m2++;
		}
		else
		{
			ot++;
		}
	}
	if(m4 + m2 / 2 >= nn / 2)
	{
		puts("Yes");
	}
	else
	{
		puts("No");
	}
	return 0;
}
