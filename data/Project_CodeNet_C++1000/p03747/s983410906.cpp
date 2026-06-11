#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

const int MAXN = 100000 + 10000;

int n, m, k;
int p[MAXN], d[MAXN];
vector<int> v1, v2;
int ans[MAXN];

int main()
{
	ios::sync_with_stdio(false);
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);

	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++)
		cin >> p[i] >> d[i];

	for(int i = 1; i <= n; i++)
		(d[i] == 1 ? v1 : v2).push_back(p[i]);

	int tag = 0;
	if(d[1] == 1)
	{
		for(int i = 0; i < v2.size(); i++)
		{
			int d = ((v2[i] - p[1]) % m + m) % m;
			if(2 * k - 1 >= d)
				tag += (2 * k - d - 1) / m + 1;
		}
	}
	else
	{
		for(int i = 0; i < v1.size(); i++)
		{
			int d = ((p[1] - v1[i]) % m + m) % m;
			if(2 * k >= d)
				tag -= (2 * k - d) / m + 1;
		}
	}
	tag = (tag % n + n) % n;

	vector<pair<int, int> > arr;
	int np1 = ((p[1] + (d[1] == 1 ? k : -k)) % m + m) % m;
	for(int i = 1; i <= n; i++)
	{
		int np = ((p[i] + (d[i] == 1 ? k : -k)) % m + m) % m;
		arr.push_back(make_pair(((np - np1) % m + m) % m, np));
	}
	sort(arr.begin(), arr.end());
	for(int i = 0; i < arr.size(); i++)
		ans[tag + 1] = arr[i].second, tag = (tag + 1) % n;

	for(int i = 1; i <= n; i++)
		cout << ans[i] << endl;

	return 0;
}
