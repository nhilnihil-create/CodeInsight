#include<bits/stdc++.h>
using namespace std;
int n, a[100010];
#define pc putchar_unlocked
#define getchar getchar_unlocked
template <class T>
inline void _read(T &x)
{
	x = 0;
	char t = getchar();
	while (!isdigit(t)) t = getchar();
	while (isdigit(t))
	{
		x = x * 10 + t - '0';
		t = getchar(); 
	}
}

int main()
{
	_read(n);
	for(int i = 1; i <= n; ++i) _read(a[i]); 
	sort(a + 1, a + n + 1, greater<int>());
	for(int i = 1; i <= n; ++i)
	{
		if(i + 1 > a[i + 1])
		{
			int ans = 0;
			for(int j = i + 1; a[j] == i; ++j)ans ^= 1;
			ans |= (a[i] - i) & 1;
			if(ans) pc('F'), pc('i'), pc('r'), pc('s'), pc('t'), pc('\n');
			else pc('S'), pc('e'), pc('c'), pc('o'), pc('n'),  pc('d'), pc('\n');
			return 0;
		}
	}
	return 0;
}