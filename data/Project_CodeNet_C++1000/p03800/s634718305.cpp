#include <bits/stdc++.h>
#define DEBUG fprintf(stderr, "Passing [%s] line %d\n", __FUNCTION__, __LINE__)
#define File(x) freopen(x".in","r",stdin); freopen(x".out","w",stdout)

using namespace std;

typedef long long LL;
typedef pair <int, int> PII;
typedef pair <int, PII> PIII;

template <typename T>
inline T gi()
{
	T f = 1, x = 0; char c = getchar();
	while (c < '0' || c > '9') {if (c == '-') f = -1; c = getchar();}
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return f * x;
}

const int INF = 0x3f3f3f3f, N = 100003, M = N << 1;

int n;
char s[N];
int a[N];

inline void out()
{
	for (int i = 1; i <= n; i+=1) if (a[i] == 1) cout << 'S'; else cout << 'W';
	puts("");
}

int main()
{
	//File("in");
	n = gi <int> ();
	scanf("%s", s + 1);
	for (int i = 1; i <= 2; i+=1)
		for (int j = 1; j <= 2; j+=1)
		{
			a[1] = i, a[2] = j;
			for (int k = 3; k <= n; k+=1)
				if (s[k - 1] == 'o')
				{
					if (a[k - 1] == 1) a[k] = a[k - 2];
					else a[k] = 3 - a[k - 2];
				}
				else
				{
					if (a[k - 1] == 1) a[k] = 3 - a[k - 2];
					else a[k] = a[k - 2];
				}
			bool fl1 = false, fl2 = false;
			if (s[n] == 'o')
			{
				if (a[n] == 1 && a[n - 1] == a[1]) fl1 = true;
				if (a[n] == 2 && a[n - 1] != a[1]) fl1 = true;
			}
			else
			{
				if (a[n] == 1 && a[n - 1] != a[1]) fl1 = true;
				if (a[n] == 2 && a[n - 1] == a[1]) fl1 = true;
			}
			if (s[1] == 'o')
			{
				if (a[1] == 1 && a[n] == a[2]) fl2 = true;
				if (a[1] == 2 && a[n] != a[2]) fl2 = true;
			}
			else
			{
				if (a[1] == 1 && a[n] != a[2]) fl2 = true;
				if (a[1] == 2 && a[n] == a[2]) fl2 = true;
			}
			if (fl1 && fl2) {out(); return 0;}
		}
	puts("-1");
	return 0;
}
