#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <vector>
using namespace std;
#define ll long long
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define lowbit(x) (x & -x)
#define lrt nl, nr, rt << 1
#define rrt nl, nr, rt << 1 | 1
const ll Inf = 1e18;
const int inf = 0x3f3f3f3f;
inline int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
	while (isdigit(ch)) { x = x * 10 + ch - '0'; ch = getchar(); }
	return f * x;
}

int main(void)
{
	int n, a;
	cin >> n >> a;
	cout << n * n - a << endl;
	return 0;
}