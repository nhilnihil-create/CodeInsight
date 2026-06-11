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
	int N;
	cin >> N;
	ll A, B, C, D;
	cin >> A >> B >> C >> D;
	auto E = abs(B - A);

	auto ans = "NO";
	for (auto i = 0; i <= N - 1; i += 2)
	{
		auto minE = (-D + C) * i / 2 + (N - 1 - i) * C;
		auto maxE = (D - C) * i / 2 + (N - 1 - i) * D;
		if (minE <= E && E <= maxE)
		{
			ans = "YES";
			break;
		}
	}
	cout << ans << endl;

	return 0;
}