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
typedef unsigned long long ull;
typedef long long ll;

int main()
{
	int N, x;
	cin >> N >> x;

	if (x == 1 || x == 2 * N - 1)
	{
		cout << "No" << endl;
	}
	else
	{
		set<int> s;
		vector<int> result(2 * N - 1);
		result[N - 1] = x;
		s.insert(x);
		result[N - 2] = x - 1;
		s.insert(x - 1);
		result[N] = x + 1;
		s.insert(x + 1);
		if (N > 2 && x < 2 * N - 2)
		{
			result[N - 3] = x + 2;
			s.insert(x + 2);
		}
		if (N > 2 && x > 2)
		{
			result[N + 1] = x - 2;
			s.insert(x - 2);
		}

		auto count = 0;
		for (auto i = 1; i <= result.size(); ++i)
		{
			if (s.find(i) != s.end())
			{
				continue;
			}

			while (count < result.size() && result[count] != 0)
			{
				++count;
			}
			if (count < result.size())
			{
				result[count] = i;
			}
		}

		cout << "Yes" << endl;
		for (auto i = 0; i < result.size(); ++i)
		{
			cout << result[i] << endl;
		}
	}

	return 0;
}