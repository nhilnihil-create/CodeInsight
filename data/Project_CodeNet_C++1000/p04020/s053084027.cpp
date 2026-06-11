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
	int N;
	cin >> N;
	auto result = 0ll;
	auto prev = 0;
	for (auto i = 0; i < N; ++i)
	{
		ll A;
		cin >> A;
		result += (A + prev) / 2;
		if (A > 0)
		{
			prev = (A - prev) % 2;
		}
		else
		{
			prev = 0;
		}
	}

	cout << result << endl;

	return 0;
}