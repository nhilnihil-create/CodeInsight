#include <cstdio>

const int MN = 100005;

char s[MN];
int a, b, c, d;

int main() {
	scanf("%s", s + 1);
	for (int i = 1; s[i]; ++i) {
		if (s[i] == 'N') ++a;
		if (s[i] == 'S') ++b;
		if (s[i] == 'E') ++c;
		if (s[i] == 'W') ++d;
	}
	puts((a && !b) || (b && !a) || (c && !d) || (d && !c) ? "No" : "Yes");
	return 0;
}