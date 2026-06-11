#include <cstdio>

const int MN = 200005;

char s[MN], t[MN];
int tp;

int main() {
	scanf("%s", s + 1);
	for (int i = 1; s[i]; ++i) {
		if (tp && t[tp] == 'S' && s[i] == 'T') --tp;
		else t[++tp] = s[i];
	}
	printf("%d\n", tp);
	return 0;
}