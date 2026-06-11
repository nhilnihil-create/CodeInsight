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
	long long N, X;
	cin >> N >> X;

	auto sum = X;

	auto l = N;
	auto w = N - X;

	auto isFirst = true;
	while (true)
	{
		if (l % w == 0)
		{
			if (isFirst)
			{
				sum += (l / w - 1) * 2 * w;
			}
			else
			{
				sum += (l / w * 2 - 1) * w;
			}
			break;
		}

		if (isFirst)
		{
			sum += (l / w * 2 - 1) * w;
		}
		else
		{
			sum += (l / w) * 2 * w;
		}
		isFirst = false;

		auto prevW = w;
		w = l % w;
		l = prevW;
	}

	cout << sum << endl;

	return 0;
}