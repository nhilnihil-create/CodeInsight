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
	int64 nn, mm;
	cin >> nn >> mm;
	char tmp;
	bool aa[nn][nn], bb[mm][mm], flag = false;
	for(int64 ii = 0;ii < nn;ii++)
	{
		for(int64 jj = 0;jj < nn;jj++)
		{
			cin >> tmp;
			if(tmp == '#')
			{
				aa[ii][jj] = true;
			}
			else
			{
				aa[ii][jj] = false;
			}
		}
	}
	for(int64 ii = 0;ii < mm;ii++)
	{
		for(int64 jj = 0;jj < mm;jj++)
		{
			cin >> tmp;
			if(tmp == '#')
			{
				bb[ii][jj] = true;
			}
			else
			{
				bb[ii][jj] = false;
			}
		}
	}
	for(int64 ii = 0;ii <= (nn - mm);ii++)
	{
		for(int64 jj = 0;jj <= (nn - mm);jj++)
		{
			flag = true;
			for(int64 kk = 0;kk < mm;kk++)
			{
				for(int64 ll = 0;ll < mm;ll++)
				{
					if(aa[ii + kk][jj + ll] != bb[kk][ll])
					{
						flag = false;
					}
				}
			}
			if(flag)
			{
				puts("Yes");
				return 0;
			}
		}
	}
	puts("No");
	return 0;
}
