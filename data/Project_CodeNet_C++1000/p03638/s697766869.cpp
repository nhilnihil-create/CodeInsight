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
	int64 hh, ww, nn, aa, pp = 0;
	cin >> hh >> ww >> nn;
	int64 memo[hh][ww];
	for(int64 ii = 1;ii <= nn;ii++)
	{
		cin >> aa;
		for(int64 jj = 0;jj < aa;jj++)
		{
			memo[pp / ww][pp % ww] = ii;
			pp++;
		}
	}
	for(int64 ii = 0;ii < hh;ii++)
	{
		if(ii % 2 == 0)
		{
			for(int64 jj = 0;jj < ww;jj++)
			{
				cout << memo[ii][jj];
				if(jj != ww - 1)
				{
					cout << ' ';
				}
			}
			cout << '\n';
		}
		else
		{
			for(int64 jj = ww - 1;jj >= 0;jj--)
			{
				cout << memo[ii][jj];
				if(jj != 0)
				{
					cout << ' ';
				}
			}
			cout << '\n';
		}
	}
	return 0;
}
