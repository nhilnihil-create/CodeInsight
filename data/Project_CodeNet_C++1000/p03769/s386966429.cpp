#include<iostream>
#include<string>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn = 100010;
ll n;
ll a[200], b[200];

//这题我是真的不会，直接抄了
int main()
{
	cin >> n;
	int p1 = 0, p2 = 0, m = 100;
	++n;
	while (n > 1)
	{
		if (n & 1) a[++p1] = m--, --n;
		else b[++p2] = m--, n >>= 1;
	}
	printf("%d\n", p1 + p2 << 1);
	for (int i = 1; i <= p1; ++i)
		printf("%d ", a[i]);
	for (int i = p2; i >= 1; --i)
		printf("%d ", b[i]);
	for (int i = 101 - p1 - p2; i <= 100; ++i)
		printf("%d ", i);
	puts("");
	return 0;
}