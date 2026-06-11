#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cmath>
#include <bitset>
#define R register
#define IN inline
#define gc getchar()
#define W while
#define MX 5050
template <class T>
IN void in(T &x)
{
	x = 0; R char c = gc;
	W (!isdigit(c)) c = gc;
	W (isdigit(c))
	x = (x << 1) + (x << 3) + c -48, c = gc;
}
std::bitset <MX> bt;
int num, kth, dat[MX];
IN bool check(const int &now)
{
	bt.reset();
	bt[0] = true; int bd = kth - dat[now];
	for (R int i = 1; i <= num; ++i) if(i != now) bt |= bt << dat[i];
	for (R int i = kth - 1; i >= bd; --i) if(bt[i]) return true;
	return false;
}
int main(void)
{
	in(num); in(kth);
	for (R int i = 1; i <= num; ++i) in(dat[i]);
	std::sort(dat + 1, dat + 1 + num);
	int ans = 0, mid, lef = 1, rig = num;
	W (lef <= rig)
	{
		mid = lef + rig >> 1;
		if(!check(mid)) ans = mid, lef = mid + 1;
		else rig = mid - 1;
	}
	printf("%d", ans);
}