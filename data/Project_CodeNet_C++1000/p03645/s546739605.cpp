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
	int64 nn, mm, tmp1, tmp2;
	cin >> nn >> mm;
	bool memo1[nn], memo2[nn];
	for(int64 ii = 0;ii < nn;ii++)
	{
		memo1[ii] = false;
		memo2[ii] = false;
	}
	for(int64 ii = 0;ii < mm;ii++)
	{
		cin >> tmp1 >> tmp2;
		tmp1--;
		tmp2--;
		if(tmp1 == 0)
		{
			memo1[tmp2] = true;
		}
		if(tmp2 == nn - 1)
		{
			memo2[tmp1] = true;
		}
	}
	for(int64 ii = 1;ii < nn - 1;ii++)
	{
		if(memo1[ii] && memo2[ii])
		{
			puts("POSSIBLE");
			return 0;
		}
	}
	puts("IMPOSSIBLE");
	return 0;
}