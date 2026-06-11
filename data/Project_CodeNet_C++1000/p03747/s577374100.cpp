#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

inline int getint()
{
	static char c;
	while ((c = getchar()) < '0' || c > '9');

	int res = c - '0';
	while ((c = getchar()) >= '0' && c <= '9')
		res = res * 10 + c - '0';
	return res;
}

const int MaxN = 100000;

int n, l, t;
int pos[MaxN];

int main()
{
	cin >> n >> l >> t;

	int s = 0;
	for (int i = 0; i < n; ++i)
	{
		pos[i] = getint();

		if (getint() == 1)
		{
			int k = (pos[i] + t) / l;
			s = (s + k) % n;
			pos[i] = (pos[i] + t) % l;
		}
		else
		{
			int k = (t + l - pos[i] - 1) / l;
			s = ((s - k) % n + n) % n;
			pos[i] = ((pos[i] - t) % l + l) % l;
		}
	}

	sort(pos, pos + n);

	for (int i = s; i < n; ++i)
		cout << pos[i] << endl;
	for (int i = 0; i < s; ++i)
		cout << pos[i] << endl;

	return 0;
}