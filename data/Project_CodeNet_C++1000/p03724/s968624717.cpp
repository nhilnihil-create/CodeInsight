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
	int N, M; cin >> N >> M;
	vector<int> counts(N, 0);
	for (int i = 0; i < M; ++i)
	{
		int ai, bi; cin >> ai >> bi;
		++counts[ai - 1];
		++counts[bi - 1];
	}
	bool isYes = true;
	for (int count : counts)
	{
		if (count % 2 == 1)
		{
			isYes = false;
			break;
		}
	}
	cout << (isYes ? "YES" : "NO") << endl;
}