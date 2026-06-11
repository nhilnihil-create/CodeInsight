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

// O(|s|)
bool OK(string s)
{
	char f = s.front();
	for (char ch : s)
	{
		if (ch != f) return false;
	}
	return true;
}

// O(|s|^2)
int Comp(string s, char ch)
{
	int ret = 0;
	for (;;)
	{
		if (OK(s)) break; // O(|s|)
		string next = "";
		for (int i = 0; i < s.length() - 1; ++i)
		{
			if (s[i] == ch || s[i + 1] == ch)
			{
				next += ch;
			}
			else
			{
				next += s[i];
			}
		}
		++ret;
		s = next;
	}
	return ret;
}

int main()
{
	string s; cin >> s;
	int ans = 10000;
	// あり得る全ての文字についてシミュレーション
	// O(26 * |s|^2)
	for (char ch = 'a'; ch <= 'z'; ++ch)
	{
		ans = min(ans, Comp(s, ch));
	}
	cout << ans << endl;
}
