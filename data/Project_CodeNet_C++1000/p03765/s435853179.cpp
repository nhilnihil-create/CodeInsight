#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
#define X first
#define Y second
#define pb push_back
typedef pair<int, int> ii;
typedef long long ll;

const int maxn = 1e5+5;

char s[maxn];
char t[maxn];

int qs[maxn], qt[maxn];

int main()
{
	scanf("%s %s", s+1, t+1);
	int n = strlen(s+1), m = strlen(t+1);
	for(int i = 1; i<= n; i++)
	{
		qs[i] = (s[i] == 'A')?1:2;
		qs[i] += qs[i-1];
	}
	for(int i = 1; i<= m; i++)
	{
		qt[i] = (t[i] == 'A')?1:2;
		qt[i] += qt[i-1];
	}
	int q; scanf("%d", &q);
	while(q--)
	{
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		int x = qs[b]-qs[a-1];
		int y = qt[d]-qt[c-1];
		if(x%3 == y%3) puts("YES");
		else puts("NO");
	}
}