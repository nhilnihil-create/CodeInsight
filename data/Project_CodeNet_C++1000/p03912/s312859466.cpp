#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>
#include <bitset>
#include <map>
#include <set>
#include <tuple>
#include <string.h>
#include <math.h>
#include <random>
#include <functional>
#include <assert.h>
#include <math.h>
#define all(x) (x).begin(), (x).end()
#define xx first
#define yy second

using namespace std;

using i64 = long long int;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	vector<int> arr(n);
	vector<int> mod(m);
	map<int, int> count;

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);

		mod[arr[i] % m]++;
		count[arr[i]]++;
	}	
	
	vector<int> eqpair(m);

	for (auto& c : count)
		eqpair[c.xx % m] += c.yy / 2;

	int ans = 0;

	for (int i = 0; i <= m - i; i++)
	{
		if (i == 0 || i == m - i)
		{
			ans += mod[i] / 2;
			continue;
		}

		int maxp = 0;
		for (int j = 0; j <= eqpair[i]; j++)
		{
			int mr = mod[i] - j * 2;
			int p = j;

			if (mr >= mod[m - i])
				p += mod[m - i];
			else
			{
				int maxe = min(eqpair[m-i], (mod[m - i] - mr) / 2);
				p += maxe;
				int mir = mod[m - i] - maxe * 2;
				p += min(mir, mr);
			}

			maxp = max(p, maxp);
		}

		ans += maxp;
	}

	printf("%d\n", ans);

	return 0;
}