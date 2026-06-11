#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define REP(i, n) for(int i = 0; i < n; ++i)
using namespace std;
using LLONG = long long;
const LLONG MOD = 1000000007;

int main()
{
	int H, W; cin >> H >> W;
	map<char, int> ch2NumMap;
	REP(i, H * W) {
		char ch; cin >> ch; ++ch2NumMap[ch];
	}
	int fourPairNum = (H / 2) * (W / 2);
	int twoPairNum = (H % 2) * (W / 2) + (H / 2) * (W % 2);
	int singleNum = (H % 2 == 1 && W % 2 == 1) ? 1 : 0;
	if (singleNum == 1)
	{
		for (auto &kvp : ch2NumMap)
		{
			if (kvp.second % 4 == 1 || kvp.second % 4 == 3)
			{
				--singleNum;
				--kvp.second;
				break;
			}
		}
	}
	for (auto &kvp : ch2NumMap)
	{
		int max = kvp.second / 4;
		kvp.second -= std::min(fourPairNum * 4, max * 4);
		fourPairNum -= std::min(fourPairNum, max);
	}
	for (auto &kvp : ch2NumMap)
	{
		int max = kvp.second / 2;
		kvp.second -= std::min(twoPairNum * 2, max * 2);
		twoPairNum -= std::min(twoPairNum, max);
	}
	bool isYes = true;
	for (const auto &kvp : ch2NumMap)
	{
		if (kvp.second != 0)
		{
			isYes = false;
			break;
		}
	}
	cout << (isYes ? "Yes" : "No") << endl;
}