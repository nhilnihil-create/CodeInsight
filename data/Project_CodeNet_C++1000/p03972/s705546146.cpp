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
	int W, H;
	cin >> W >> H;
	vector<pair<long long, int>> list;
	for (auto i = 0; i < W; ++i)
	{
		long long temp;
		cin >> temp;
		list.push_back(make_pair(temp, i));
	}
	for (auto i = 0; i < H; ++i)
	{
		long long temp;
		cin >> temp;
		list.push_back(make_pair(temp, i + W));
	}

	sort(list.begin(), list.end());

	auto x = W + 1;
	auto y = H + 1;
	auto result = 0ll;
	for (auto& p : list)
	{
		auto rem = x;
		if (p.second < W)
		{
			rem = y;
			--x;
		}
		else
		{
			--y;
		}
		result += p.first * rem;
	}
	cout << result << endl;

	return 0;
}