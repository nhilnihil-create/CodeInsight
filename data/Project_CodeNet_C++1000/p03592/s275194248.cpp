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
	
	int n, m, k;

	cin >> n >> m >> k;

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			int x = n * j + (m - j) * i - j * i;
			//cout << i << ' ' << j << ' ' << x << '\n';
			if (x == k)
			{
				cout << "Yes" << '\n';
				return 0;
			}
		}
	}

	cout << "No" << '\n';

	return 0;
}