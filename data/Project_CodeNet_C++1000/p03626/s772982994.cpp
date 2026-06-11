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
	string S[2];
	cin >> N;
	cin >> S[0];
	cin >> S[1];

	auto isFirst = true;
	auto isPrevHorizontal = false;
	auto count = 1ull;
	auto mod = 1000000007;
	for (auto i = 0; i < N; ++i)
	{
		auto isNextHorizontal = S[0][i] != S[1][i];

		if (isFirst)
		{
			isFirst = false;
			if (isNextHorizontal)
			{
				count *= 6;
			}
			else
			{
				count *= 3;
			}
		}
		else if(isPrevHorizontal)
		{
			if (isNextHorizontal)
			{
				count *= 3;
			}
		}
		else
		{
			count *= 2;
		}

		if (isNextHorizontal)
		{
			++i;
		}
		isPrevHorizontal = isNextHorizontal;
		count = count % mod;
	}

	cout << count << endl;

	return 0;
}