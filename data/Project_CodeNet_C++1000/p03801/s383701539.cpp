#include <cstdio>
#include <algorithm>
#include <cctype>
#include <cstring>
using namespace std;

namespace zyt
{
	template<typename T>
	inline void read(T &x)
	{
		char c;
		bool f = false;
		x = 0;
		do
			c = getchar();
		while (c != '-' && !isdigit(c));
		if (c == '-')
			f = true, c = getchar();
		do
			x = x * 10 + c - '0', c = getchar();
		while (isdigit(c));
		if (f)
			x = -x;	
	}
	template<typename T>
	inline void write(T x)
	{
		static char buf[20];
		char *pos = buf;
		if (x < 0)
			putchar('-'), x = -x;
		do
			*pos++ = x % 10 + '0';
		while (x /= 10);
		while (pos > buf)
			putchar(*--pos);	
	}
	typedef long long ll;
	const int N = 1e5 + 10;
	int n, id[N];
	ll arr[N], ans[N];
	bool cmparr(const int i, const int j)
	{
		return arr[i] == arr[j] ? i < j : arr[i] > arr[j];	
	}
	int work()
	{
		read(n);
		for (int i = 0; i < n; i++)
			read(arr[i]), id[i] = i;
		sort(id, id + n, cmparr);
		int fir = 0, sec = 1;
		while (sec < n)
		{
			while (sec < n && arr[id[sec]] == arr[id[sec - 1]])
				sec++;
			if (sec == n)
				break;
			ans[id[fir]] += (ll)(arr[id[fir]] - arr[id[sec]]) * sec;
			if (id[fir] > id[sec])
				fir = sec;
			else
				arr[id[fir]] = arr[id[sec]];
			sec++;
		}
		ans[id[fir]] += arr[id[fir]] * n;
		for (int i = 0; i < n; i++)
			write(ans[i]), putchar('\n');
		return 0;	
	}	
}
int main()
{
	return zyt::work();	
}