#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <cstdlib>
#include <vector>
#include <string>
#include <bitset>
#include <math.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
 
typedef long long ll;
typedef long double ld;
 
const ll MOD = 1e9 + 7, INF = 1e18 + 1;
 
using namespace std;

vector <int> g[1000000];

int a[1000000], n;

int dfs (int x, int p)
{
	for (int to : g[x])
		if (to != p)
			a[x] ^= dfs (to, x) + 1;

	return a[x];
}

int main ()
{
	cin >> n;

	for (int i = 0; i < n - 1; i++)
	{
		int u, v;

		scanf ("%d%d", &u, &v);

		g[u-1].push_back (v - 1);
		g[v-1].push_back (u - 1);
	}

	if (dfs (0, -1)) cout << "Alice";
	else cout << "Bob";
}