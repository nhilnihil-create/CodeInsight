#include <bits/stdc++.h>
using namespace std;

const int MAXN = 505;

int n, a[MAXN];
int v[MAXN*MAXN];

pair<int,int> pos[MAXN];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), v[a[i]] = i, pos[i] = make_pair(a[i], i);
	sort(pos+1, pos+n+1);
	int j = 1;
	for (int t = 1; t <= n; t++) {
		int i = pos[t].second;
		for (int k = 1; k < i; k++) {
			while (j <= n*n && v[j]) j++;
			if (j >= a[i]) {
				puts("No");
				return 0;
			}
			v[j++] = i;
		}
	}
	j = n*n;
	for (int t = n; t >= 1; t--) {
		int i = pos[t].second;
		for (int k = 1; k <= n-i; k++) {
			while (j > 0 && v[j]) j--;
			if (j <= a[i]) {
				puts("No");
				return 0;
			}
			v[j--] = i;
		}
	}
	puts("Yes");
	for (int i = 1; i <= n*n; i++)
	        printf("%d ", v[i]);
	puts("");
	return 0;
}
