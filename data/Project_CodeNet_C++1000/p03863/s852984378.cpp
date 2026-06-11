#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <functional>
#include <cmath>
#include <set>
#include <queue>
#include <deque>
#include <vector>
#include <climits>
#include <sstream>
#include <iomanip>
#include <map>
#include <stack>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

int main()
{
	string s;
	cin >> s;

	vector<bool> exist(30);
	for (auto i = 0; i < (int)s.length(); ++i)
	{
		exist[s[i] - 'a'] = true;
	}

	auto num = 0;
	for (auto i = 0; i < (int)exist.size(); ++i)
	{
		if (exist[i])
		{
			++num;
		}
	}

	auto first = true;
	if (num <= 2)
	{
		first = false;
	}
	else if (s[0] == s[(int)s.length() - 1])
	{
		if (s.length() % 2 == 1)
		{
			first = false;
		}
	}
	else
	{
		if (s.length() % 2 == 0)
		{
			first = false;
		}
	}

	if (first)
	{
		cout << "First" << endl;
	}
	else
	{
		cout << "Second" << endl;
	}

	return 0;
}