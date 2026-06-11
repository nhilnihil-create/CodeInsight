#include <bits/stdc++.h>
#define ll long long
#define uint unsigned long long
#define db double
#define ls x << 1
#define rs x << 1 | 1
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define eps 1e-9
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

int n, m;
int a[100010];

int main()
{
	n = read();
	m = read();
	vi ji, ou;
	rep(i, 1, m)
	{
		a[i] = read();
		if (a[i] & 1) ji.pb(a[i]);
		else ou.pb(a[i]);
	}
	if (n == 1) printf("1\n1\n1\n");
	else
	{
		int jis = ji.size();
		int osz = ou.size();
		if (jis > 2) puts("Impossible");
		else
		{
			if (jis == 0)
			{
				rep(i, 0, osz - 2) printf("%d ", ou[i]);
				printf("%d\n", ou[osz - 1]);
				printf("%d\n", osz + 1);
				printf("1 ");
				rep(i, 0, osz - 2) printf("%d ", ou[i]);
				printf("%d\n", ou[osz - 1] - 1);
			}
			else if (jis == 1)
			{
				if (osz == 0)
				{
					printf("%d\n", ji[0]);
					printf("2\n");
					printf("%d %d\n", ji[0] - 1, 1);
				}
				else
				{
					printf("%d ", ji[0]);
					rep(i, 0, osz - 2) printf("%d ", ou[i]);
					printf("%d\n", ou[osz - 1]);
					printf("%d\n", m);
					printf("%d ", ji[0] + 1);
					rep(i, 0, osz - 2) printf("%d ", ou[i]);
					printf("%d\n", ou[osz - 1] - 1);
				}
			}
			else if (jis == 2)
			{
				if (osz == 0)
				{
					if (ji[0] == 1 && ji[1] == 1) printf("1 1\n1\n2\n");
					else
					{
						sort(ji.begin(), ji.end());
						printf("%d %d\n", ji[0], ji[1]);
						printf("2\n");
						printf("%d %d\n", ji[0] + 1, ji[1] - 1);
					}
				}
				else
				{
					printf("%d ", ji[0]);
					rep(i, 0, osz - 1) printf("%d ", ou[i]);
					printf("%d\n", ji[1]);
					vi r;
					r.pb(ji[0] + 1);
					rep(i, 0, osz - 1) r.pb(ou[i]);
					if (ji[1] - 1) r.pb(ji[1] - 1);
					printf("%d\n", r.size());
					int sz = r.size();
					rep(i, 0, sz - 1)
						if (i == sz - 1) printf("%d\n", r[i]);
						else printf("%d ", r[i]);
				}
			}
		}
	}
	return 0;
}
