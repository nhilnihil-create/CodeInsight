#include <algorithm>
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
	string S; cin >> S;
	map<char, int> ch2NumMap;
	for (const char ch : S)
	{
		++ch2NumMap[ch];
	}
	bool isYes = true;;
	if (ch2NumMap.count('N') > 0 || ch2NumMap.count('S') > 0)
	{
		if (ch2NumMap.count('N') == 0 || ch2NumMap.count('S') == 0)
		{
			isYes = false;
		}
	}
	if (ch2NumMap.count('E') > 0 || ch2NumMap.count('W') > 0)
	{
		if (ch2NumMap.count('E') == 0 || ch2NumMap.count('W') == 0)
		{
			isYes = false;
		}
	}
	cout << (isYes ? "Yes" : "No") << endl;
}