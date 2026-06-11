#include <stdio.h>
int d, k, x;
char s[100001];
int main() {
	scanf("%s", s);
	scanf("%d", &k);
	while (s[d] != NULL)d++;
	for (int i = 0; i < d; i++) {
		x = 26 - (s[i] - 'a');
		x %= 26;
		if (x <= k) {
			k -= x;
			s[i] = 'a';
		}
	}
	k %= 26;
	s[d - 1] = 'a' + (s[d - 1] + k - 'a') % 26;
	printf("%s\n", s);
}