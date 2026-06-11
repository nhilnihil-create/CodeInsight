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
LL getans(LL a, LL b, LL c)
{
	if (min({ a,b,c }) == 0) return INF * INF;
	return max({ a,b,c }) - min({ a,b,c });
}
LL solve(int h, int w)
{
	LL ans = INF * INF;
	for (int i = 1; i <= h; i++)
	{
		ans = min({
			ans,
			getans(1LL * i * w, (h - i) / 2LL * w, (h - i - (h - i) / 2LL) * w),
			getans(1LL * i * w,(h - i) * (w / 2LL),(h - i) * (w - w / 2LL))
			});
	}
	return ans;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int h, w;
	cin >> h >> w;
	cout << min(solve(h, w), solve(w, h)) << endl;
	return 0;
}