#include <bits/stdc++.h>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back
#define mset(x, y) memset(x, y, sizeof x)
#define mcpy(x, y) memcpy(x, y, sizeof x)
using namespace std;

typedef long long LL;
typedef pair <int, int> pii;

inline int Read()
{
	int x = 0, f = 1, c = getchar();
	for (; !isdigit(c); c = getchar())
		if (c == '-')
			f = -1;
	for (;  isdigit(c); c = getchar())
		x = x * 10 + c - '0';
	return x * f;
}

LL l, r, mid, ret;

inline bool Ask(LL x)
{
	string s;
	cout << "? " << x << endl;
	cin >> s;
	return s == "Y";
}

int main()
{
	if (Ask(10000000000))
		for (ret = 2; ; ret *= 10)
			if (Ask(ret))
				return cout << "! " << ret / 2 << endl, 0;
	for (r = 10; ; r *= 10)
		if (!Ask(r))
			break;
	for (l = r / 10, r --; l < r; )
		if (Ask((mid = l + r >> 1) * 10))
			r = mid;
		else
			l = mid + 1;
	return cout << "! " << r << endl, 0;
}
