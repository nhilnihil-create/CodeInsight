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
	int K; cin >> K;
	REP(i, s.length())
	{
		int x = static_cast<int>(s[i] - 'a');
		int dist = (26 - x) % 26;
		if (K >= dist)
		{
			K -= dist;
			s[i] = 'a';
		}
	}
	if (K > 0)
	{
		auto itr = s.rbegin();
		int x = static_cast<int>(*itr - 'a');
		x = (x + K) % 26;
		*itr = static_cast<char>('a' + x);
	}
	cout << s << endl;
}