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
	string ss;
	int64 aa, zz;
	cin >> ss;
	for(int64 ii = 0;ii < ss.length();ii++)
	{
		if(ss[ii] == 'A')
		{
			aa = ii;
			break;
		}
	}
	for(int64 ii = ss.length() - 1;ii >= 0;ii--)
	{
		if(ss[ii] == 'Z')
		{
			zz = ii;
			break;
		}
	}
	cout << zz - aa  + 1 << endl;
	return 0;
}
