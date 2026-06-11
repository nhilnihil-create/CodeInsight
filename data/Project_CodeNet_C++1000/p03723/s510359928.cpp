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

using namespace std;
using LLONG = long long;
const LLONG MOD = 1000000007;

int main()
{
	int A, B, C; cin >> A >> B >> C;
	int ans = 0;
	// シミュレーションを行う
	for (;;)
	{
		if (A % 2 == 1 || B % 2 == 1 || C % 2 == 1) break;
		int nA = (B + C) / 2;
		int nB = (C + A) / 2;
		int nC = (A + B) / 2;
		++ans;
		// 交換後，交換前と変わらなければ無限に続く
		vector<int> prev{ A, B, C }; sort(prev.begin(), prev.end());
		vector<int> next{ nA, nB, nC }; sort(next.begin(), next.end());
		if (prev == next)
		{
			ans = -1;
			break;
		}
		A = nA;
		B = nB;
		C = nC;
	}
	cout << ans << endl;
}