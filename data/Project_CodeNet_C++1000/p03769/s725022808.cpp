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
ll n;
deque<int> ans;
int main()
{
	rg ll cnt = 1;
	cin >> n;
	if (n == 1)
	{
		printf("2\n1 1\n");
		return 0;
	}
	while (cnt <= n)
		cnt <<= 1;
	cnt >>= 1;
	rg int i;
	ans.push_front(i = 1);
	n ^= cnt;
	cnt >>= 1;
	while (cnt)
	{
		if (n & cnt)
			ans.push_back(++i);
		if (cnt != 1)
			ans.push_front(++i);
		cnt >>= 1;
	}
	ans.push_back(++i);
	cout << 2 * i << '\n';
	for (int j = 1; j <= i; j++)
		cout << j << ' ';
	while (!ans.empty())
	{
		cout << i - ans.front() + 1 << ' ';
		ans.pop_front();
	}
	putchar('\n');
	return 0;
}