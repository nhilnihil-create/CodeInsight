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
	string ss;
	cin >> ss;
	for(int64 ii = 1;ii < ss.length();ii++)
	{
		if(ss[ii - 1] == ss[ii])
		{
			cout << ii << ' ' << ii + 1 << endl;
			return 0;
		}
	}
	for(int64 ii = 1;ii < ss.length() - 1;ii++)
	{
		if(ss[ii - 1] == ss[ii + 1])
		{
			cout << ii << ' ' << ii + 2 << endl;
			return 0;
		}
	}
	cout << "-1 -1" << endl;
	return 0;
}