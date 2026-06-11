#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const long double eps = 1e-8;

inline int read()
{
	int a = 0, c;
	do c = getchar(); while (!isdigit(c));
	while (isdigit(c)) {
		a = a*10+c-'0';
		c = getchar();
	}
	return a;
}

int n, mod, T;
int x[MAXN], w[MAXN];
int a[MAXN];
pair<int,int> p[MAXN];

int main()
{
	n = read(), mod = read(), T = read();
	int pox = -1, poy = -1, c = 0;
	for (int i = 0; i < n; i++) {
		x[i] = read(), w[i] = read();
		if (w[i] == 1) pox = i, c++;
		else poy = i;
	}
	if (pox == -1) {
		for (int i = 0; i < n; i++)
			printf("%d\n", ((x[i]-T)%mod+mod)%mod);
	} else if (poy == -1) {
		for (int i = 0; i < n; i++)
			printf("%d\n", ((x[i]+T)%mod+mod)%mod);
	} else {
		int cnt = pox;
		for (int i = 0; i < n; i++)
			if (w[i] == 2) {
				int T_first = i > pox ? (x[i]-x[pox]) : mod-(x[pox]-x[i]);
			        if (T_first > T*2) continue;
				cnt = (cnt+1ll+(2*T-T_first)/mod)%n;
			}
		for (int i = 0; i < n; i++) {
			if (w[i] == 1)
				p[i] = make_pair((x[i]+T)%mod, i);
			else p[i] = make_pair(((x[i]-T)%mod+mod)%mod, i);
		}
		// cerr << pox << " " << cnt << endl;
		sort(p, p+n);
		int pp = 0;
		for (int i = 0; i < n; i++) {
			// cerr << p[i].first << " ";
			if (p[i].second == pox)
				pp = i;
		}
		// cerr << endl;
		for (int i = pp, c = cnt; i < pp+n; i++, c = (c+1)%n)
			a[c%n] = p[i%n].first;
		for (int i = 0; i < n; i++)
			printf("%d\n", a[i]);
	}
	return 0;
}
