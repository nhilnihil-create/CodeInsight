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
	for(int64 ii = 0;ii < ss.length();ii++)
	{
		if(ii == 5 || ii == 13)
		{
			cout << ' ';
		}
		else
		{
			cout << ss[ii];
		}
	}
	cout << endl;
	return 0;
}