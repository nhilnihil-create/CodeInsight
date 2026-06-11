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
	ll N, A, B, C, D;
	cin >> N >> A >> B >> C >> D;

	auto diff = abs(A - B);
	auto result = false;
	for (auto i = 0; i <= N - 1; i += 2)
	{
		auto x = N - 1 - i;
		if (x * C - i / 2 * (D - C) <= diff && diff <= x * D + i / 2 * (D - C))
		{
			result = true;
			break;
		}
	}

	if (result)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}

	return 0;
}