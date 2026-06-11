#include <bits/stdc++.h>
using namespace std;
char s[100007];
int a[128];
int main() {
	a['b'] = 0, a['p'] = 1, a['d'] = 2, a['q'] = 3;
	scanf("%s", s + 1);
	for (int l = strlen(s + 1), i = 1; i <= (l >> 1) + 1; ++i)
		if (a[s[i]] ^ ((a[s[l - i + 1]] + 2) % 4))
			return printf("No\n"), 0;
	return printf("Yes\n"), 0;
}