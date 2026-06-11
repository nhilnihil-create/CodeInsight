#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e3 + 10;
int a[N];
bitset<N> b1[N], b2[N];
vector<int> refrain(bitset<N>& b, int k, int o = 0)
{
	vector<int> ret;
	for (int i = 0; i < k; i++)
	{
		if (b[i])
			ret.push_back(i + o);
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	int sz = 0;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		if (x >= k) continue;
		a[++sz] = x;
	}
	n = sz;
	b1[0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		b1[i] = b1[i - 1] | (b1[i - 1] << a[i]);
	}
	b2[n + 1][0] = 1;
	for (int i = n; i >= 1; i--)
	{
		b2[i] = b2[i + 1] | (b2[i + 1] << a[i]);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		vector<int> v1 = refrain(b1[i - 1], k, a[i]), v2 = refrain(b2[i + 1], k, 0);
		int minv = INF;
		for (auto& x : v1)
		{
			while (!v2.empty() && v2.back() + x >= k)
			{
				minv = min(minv, v2.back() + x);
				v2.pop_back();
			}
		}
		if (minv - a[i] >= k) ans++;
	}
	cout << ans << endl;
	return 0;
}