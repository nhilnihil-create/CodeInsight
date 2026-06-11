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
	int64 nn, ans = 1000, tmp;
	cin >> nn;
	for(int64 ii = 1;ii <= sqrt(nn) + 1;ii++)
	{
		if(nn % ii == 0)
		{
			tmp = max((int64)((log10(ii)) + 1), (int64)((log10(nn / ii)) + 1));
			ans = min(ans, tmp);
		}
	}
	cout << ans << endl;;
	return 0;
}