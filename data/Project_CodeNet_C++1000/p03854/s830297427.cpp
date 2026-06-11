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
using namespace std;

int main()
{
	string ss;
	cin >> ss;
	reverse(ss.begin(), ss.end());
	for(int64 ii = 0;ii < ss.length();ii++)
	{
		if(ss[ii] == 'r')
		{
			if(ss.substr(ii, 7) == "remaerd")
			{
				ii += 6;
			}
			else if(ss.substr(ii, 6) == "resare")
			{
				ii += 5;
			}
			else
			{
				cout << "NO" << endl;
				return 0;
			}
		}
		else if(ss[ii] == 'm')
		{
			if(ss.substr(ii, 5) == "maerd")
			{
				ii += 4;
			}
			else
			{
				cout << "NO" << endl;
				return 0;
			}
		}
		else if(ss[ii] == 'e')
		{
			if(ss.substr(ii, 5) == "esare")
			{
				ii += 4;
			}
			else
			{
				cout << "NO" << endl;
				return 0;
			}
		}
		else
		{
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}