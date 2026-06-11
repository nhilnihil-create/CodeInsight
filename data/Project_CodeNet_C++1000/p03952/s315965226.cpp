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
	int N, x;
	cin >> N >> x;
	if (x == 1 || x == 2 * N - 1)
	{
		cout << "No" << endl;
	}
	else
	{
		vector<int> ans(2 * N - 1);
		auto mid = (2 * N - 1) / 2;
		ans[mid] = x;
		ans[mid - 1] = x - 1;
		ans[mid + 1] = x + 1;
		auto num = 1;
		for (auto i = 0; i < 2 * N - 1; ++i)
		{
			if (i >= mid - 1 && i <= mid + 1)
			{
				continue;
			}
			while (num >= x - 1 && num <= x + 1)
			{
				++num;
			}

			ans[i] = num;
			++num;
		}

		cout << "Yes" << endl;
		for (auto i = 0; i < (int)ans.size(); ++i)
		{
			cout << ans[i] << endl;
		}
	}

	return 0;
}