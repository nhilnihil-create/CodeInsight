#define _USE_MATH_DEFINES
#include <math.h>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define REP(i, n) for(int i = 0; i < n; ++i)

using namespace std;
using LLONG = long long;
const LLONG MOD = 1000000007;

int main()
{
	string s; cin >> s;
	for (int i = 0; i < 12; ++i)
	{
		cout << s[i];
		if (i == 3) cout << ' ';
	}
	cout << endl;
}