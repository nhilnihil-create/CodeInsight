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
	string ss, ans = "";
	cin >> ss;
	for(int64 ii = 0;ii < ss.length();ii++)
	{
		if(ss[ii] == 'B')
		{
			if(ans.length() != 0)
			{
				auto ite = ans.end() - 1;
				ans.erase(ite);
			}
		}
		else
		{
			ans += ss[ii];
		}
	}
	cout << ans << endl;
	return 0;
}