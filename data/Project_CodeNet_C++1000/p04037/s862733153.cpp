#include <bits/stdc++.h>
#define Inf 0x3f3f3f3f
#define rg register
#define pii pair<int, int>
#define mp(x, y) make_pair(x, y)
using namespace std;
typedef long long ll;
const int Maxn = 1e5 + 5;
typedef int arr[Maxn];
//ll Add(ll x, ll y) { return (x += y) >= Mod ? x - Mod : (x < 0 ? x + Mod : x); }
//ll Inc(ll &x, ll y) { (x += y) >= Mod ? x -= y : (x < 0 ? x += Mod : 0); }
ll min(ll x, ll y) { return x < y ? x : y; }
ll max(ll x, ll y) { return x > y ? x : y; }
inline ll read()
{
	rg ll res = 0, sign = 1;
	rg char ch = getchar();
	while (!isdigit(ch))
	{
		if (ch == '-')
			sign = -1;
		ch = getchar();
	}
	do
	{
		res = (res << 3) + (res << 1) + (ch ^ 48);
		ch = getchar();
	} while (isdigit(ch));
	return res * sign;
}
int n;
arr a;
bool cmp(int x, int y) { return x > y; }
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		a[i] = read();
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1, j; i <= n; i++)
	{
		if (i != n && a[i + 1] >= i + 1)
			continue;
		for (j = i; j < n && a[j + 1] >= i; j++);
		if ((a[i] - i) & 1 || (j - i) & 1)
		{
			puts("First");
			break;
		}
		else
		{
			puts("Second");
			break;
		}
	}
	return 0;
}
