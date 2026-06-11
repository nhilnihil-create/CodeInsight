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
const int N = 1e3 + 10;
LL dis[N];
vector<tuple<int, int, int>> vp;
LL refrain(int n, int cnt = 1)
{
	while (cnt--)
	{
		for (auto& p : vp)
		{
			int x, y, w;
			tie(x, y, w) = p;
			dis[y] = max(dis[y], dis[x] + w);
		}
	}
	return dis[n];
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	MEM(dis, 0xdf);
	dis[1] = 0;
	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		vp.emplace_back(a, b, c);
	}
	LL ans1 = refrain(n, 2 * n);
	LL ans2 = refrain(n, 2 * n);
	if (ans1 == ans2) cout << ans1 << endl;
	else cout << "inf" << endl;
	return 0;
}