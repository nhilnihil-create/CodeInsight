#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
char s[maxn], t[maxn];
int pres[maxn], pret[maxn];
int main()
{
	scanf("%s%s", s + 1, t + 1);
	int lens = strlen(s + 1), lent = strlen(t + 1);
	for(int i = 1; i <= lens; ++i)
		if(s[i] == 'B')
			pres[i] = pres[i - 1] + 1;
		else
			pres[i] = pres[i - 1] + 2;
	for(int i = 1; i <= lent; ++i)
		if(t[i] == 'B')
			pret[i] = pret[i - 1] + 1;
		else
			pret[i] = pret[i - 1] + 2;
	int q, a, b, c, d;
	scanf("%d", &q);
	while(q--)
	{
		scanf("%d%d%d%d", &a, &b, &c, &d);
		if(abs(pres[b] - pres[a - 1] - (pret[d] - pret[c - 1])) % 3 == 0)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
		