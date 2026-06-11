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
	cin >> N;
	long long A[300][300];

	for (auto i = 0; i < N; ++i)
	{
		for (auto j = 0; j < N; ++j)
		{
			cin >> A[i][j];
		}
	}

	auto isValid = true;
	for (auto k = 0; k < N; ++k)
	{
		for (auto i = 0; i < N; ++i)
		{
			for (auto j = 0; j < N; ++j)
			{
				if (A[i][j] > A[i][k] + A[k][j])
				{
					isValid = false;
				}
			}
		}
	}

	if (isValid)
	{
		auto result = 0ll;
		for (auto i = 0; i < N; ++i)
		{
			for (auto j = i + 1; j < N; ++j)
			{
				auto isAdd = true;
				for (auto k = 0; k < N; ++k)
				{
					if (i == k || j == k)
					{
						continue;
					}

					if (A[i][j] == A[i][k] + A[k][j])
					{
						isAdd = false;
						break;
					}
				}

				if (isAdd)
				{
					result += A[i][j];
				}
			}
		}

		cout << result << endl;
	}
	else
	{
		cout << "-1" << endl;
	}

	return 0;
}