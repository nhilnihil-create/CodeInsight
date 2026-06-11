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
	int N, M;
	cin >> N >> M;
	vector<bool> flag(N);
	vector<int> num(N, 1);
	flag[0] = true;
	
	for (auto i = 0; i < M; ++i)
	{
		int x, y;
		cin >> x >> y;
		--x;
		--y;

		if (flag[x])
		{
			flag[y] = true;
		}
		++num[y];
		--num[x];
		if (num[x] <= 0)
		{
			flag[x] = false;
		}
	}

	auto ans = 0;
	for (auto i = 0; i < N; ++i)
	{
		if (flag[i])
		{
			++ans;
		}
	}
	cout << ans << endl;

	return 0;
}