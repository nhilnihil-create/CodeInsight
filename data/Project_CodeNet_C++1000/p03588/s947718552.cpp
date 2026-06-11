#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional> 
#include <iomanip>
#include <unordered_map>
#include <memory.h>
#include <cstring>
#include <fstream>

using namespace std;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, a, b;
	int res = 0;
	vector <pair<int, int>> v;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}

	res = v[0].first + v[0].second;

	for (int i = 1; i < n; i++)
	{
		res = min(res, v[i].first + v[i].second);
	}

	cout << res << '\n';

	return 0;
}
