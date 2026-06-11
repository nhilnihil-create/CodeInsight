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
	int H, W;
	cin >> H >> W;

	vector<int> count(30);
	for (auto i = 0; i < H; ++i)
	{
		string a;
		cin >> a;
		for (auto j = 0; j < W; ++j)
		{
			++count[a[j] - 'a'];
		}
	}

	auto result = true;
	auto x = W;
	auto y = H;
	if (W % 2 > 0)
	{
		--x;
	}
	if (H % 2 > 0)
	{
		--y;
	}
	auto num = x * y / 4;
	for (auto i = 0; i < count.size(); ++i)
	{
		auto temp = count[i] / 4;
		if (temp > num)
		{
			temp = num;
		}
		num -= temp;
		count[i] -= temp * 4;
		if (num == 0)
		{
			break;
		}
	}

	if (num > 0)
	{
		result = false;
	}
	else
	{
		num = (W - x) * H / 2 + (H - y) * W / 2;
		for (auto i = 0; i < count.size(); ++i)
		{
			auto temp = count[i] / 2;
			if (temp > num)
			{
				temp = num;
			}
			num -= temp;
			count[i] -= temp * 2;
		}

		if (num > 0)
		{
			result = false;
		}
	}

	if (result)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}

	return 0;
}