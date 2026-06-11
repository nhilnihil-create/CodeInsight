#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;
using LLONG = long long;
const LLONG MOD = 1000000007;

int main()
{
	string S; cin >> S;
	bool isYes = true;
	while (!S.empty())
	{
		string five = S.substr(0, 5);
		if (five == "dream")
		{
			string seven = S.substr(0, 7);
			if (seven == "dreamer")
			{
				string eight = S.substr(0, 8);
				if (eight == "dreamera")
				{
					S = S.substr(5, S.length());
				}
				else
				{
					S = S.substr(7, S.length());
				}
			}
			else
			{
				S = S.substr(5, S.length());
			}
		}
		else if (five == "erase")
		{
			string six = S.substr(0, 6);
			if (six == "eraser")
			{
				S = S.substr(6, S.length());
			}
			else
			{
				S = S.substr(5, S.length());
			}
		}
		else
		{
			isYes = false;
			break;
		}
	}
	cout << (isYes ? "YES" : "NO") << endl;
}