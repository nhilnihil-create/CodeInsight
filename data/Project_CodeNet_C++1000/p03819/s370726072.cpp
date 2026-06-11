#include <iostream>
#include <cstdio>
#include <algorithm>
#define IsDigit(x) ((x) >= '0' && (x) <= '9')
#define LowBit(x) ((x) & -(x))
using namespace std;

int n, m;
int tree[100002];
struct Interval{
	int l, r;
	Interval() {}
	Interval(int x, int y)
		: l(x), r(y)
	{}
	bool operator<(const Interval &x) const{ return r - l < x.r - x.l; }
}sou[300000];


int Read(void)
{
	int c, ret(0);
	
	c = getchar();
	while (!IsDigit(c))
		c = getchar();
	do
		ret = ret * 10 + c - '0';
	while ((c = getchar()) && IsDigit(c));
	return ret;
}


void Add(const int val, int pos)
{
	while (pos <= m + 1) {
		tree[pos] += val;
		pos += LowBit(pos);
	}
	return;
}


int Sum(int pos)
{
	int ret(0);
	
	while (pos) {
		ret += tree[pos];
		pos -= LowBit(pos);
	}
	return ret;
}


int main()
{
	int l, r, pos(0), ans;
	
	n = Read();
	m = Read();
	for (int i = 0; i < n; ++i) {
		l = Read();
		r = Read();
		sou[i] = Interval(l, r);
	}
	sort(sou, sou + n);
	for (int step = 1; step <= m; ++step) {
		while (pos < n && sou[pos].r - sou[pos].l + 1 < step) {
			Add(1, sou[pos].l);
			Add(-1, sou[pos].r + 1);
			++pos;
		}
		ans = n - pos;
		for (int i = step; i <= m; i += step)
			ans += Sum(i);
		printf("%d\n", ans);
	}
	return 0;
}

