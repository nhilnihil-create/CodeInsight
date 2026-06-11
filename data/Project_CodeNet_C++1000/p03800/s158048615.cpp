#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <functional>
#include <cmath>
#include <set>
#include <queue>
#include <vector>
#include <climits>
#include <sstream>
#include <iomanip>
#include <map>
#include <stack>
using namespace std;

int main()
{
	int N;
	string s;
	cin >> N >> s;

	auto isValid = false;
	for (auto i = 0; i < 4; ++i)
	{
		string result;
		if ((i & 1) != 0)
		{
			result += "S";
		}
		else
		{
			result += "W";
		}
		if ((i & 2) != 0)
		{
			result += "S";
		}
		else
		{
			result += "W";
		}

		for (auto j = 1; j < N - 1; ++j)
		{
			auto isSame = false;
			if (result[j] == 'S')
			{
				if (s[j] == 'o')
				{
					isSame = true;
				}
			}
			else
			{
				if (s[j] == 'x')
				{
					isSame = true;
				}
			}

			if (isSame)
			{
				result += result[j - 1];
			}
			else if (result[j - 1] == 'S')
			{
				result += "W";
			}
			else
			{
				result += "S";
			}
		}

		isValid = true;
		for (auto j = N - 1; j <= N; ++j)
		{
			auto isSame = false;
			auto current = (j + N) % N;
			auto prev = (j + N - 1) % N;
			auto next = (j + N + 1) % N;
			if (result[current] == 'S')
			{
				if (s[current] == 'o')
				{
					isSame = true;
				}
			}
			else if (s[current] == 'x')
			{
				isSame = true;
			}

			if (isSame)
			{
				if (result[next] != result[prev])
				{
					isValid = false;
					break;
				}
			}
			else
			{
				if (result[next] == result[prev])
				{
					isValid = false;
					break;
				}
			}
		}

		if (isValid)
		{
			cout << result << endl;
			break;
		}
	}

	if (!isValid)
	{
		cout << "-1" << endl;
	}

	return 0;
}