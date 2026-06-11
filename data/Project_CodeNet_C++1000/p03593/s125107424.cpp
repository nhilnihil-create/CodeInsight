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
	int H, W;
	cin >> H >> W;
	vector<int> num(30);
	for (auto i = 0; i < H; ++i)
	{
		string a;
		cin >> a;
		for (auto j = 0; j < W; ++j)
		{
			++num[a[j] - 'a'];
		}
	}

	auto num1 = 0;
	auto num2 = 0;
	auto num4 = 0;
	if (H % 2 == 0)
	{
		if (W % 2 == 0)
		{
			num4 = H * W / 4;
		}
		else
		{
			num4 = (W - 1) * H / 4;
			num2 = H / 2;
		}
	}
	else
	{
		if (W % 2 == 0)
		{
			num4 = (H - 1) * W / 4;
			num2 = W / 2;
		}
		else
		{
			num4 = (W - 1) * (H - 1) / 4;
			num2 = (W - 1) / 2 + (H - 1) / 2;
			num1 = 1;
		}
	}

	for (auto i = 0; i < (int)num.size(); ++i)
	{
		auto temp = num[i] / 4;
		auto sub = min(temp, num4);
		num4 -= sub;
		num[i] -= sub * 4;
	}

	for (auto i = 0; i < (int)num.size(); ++i)
	{
		auto temp = num[i] / 2;
		auto sub = min(temp, num2);
		num2 -= sub;
		num[i] -= sub * 2;
	}

	auto remain = 0;
	for (auto i = 0; i < (int)num.size(); ++i)
	{
		remain += num[i];
	}

	if (num4 == 0 && num2 == 0 && num1 == remain)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}

	return 0;
}