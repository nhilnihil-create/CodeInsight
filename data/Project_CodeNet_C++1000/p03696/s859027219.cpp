#include <iostream>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	char s[n];
	scanf("%s", s);
	int l = 0, m = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(')
			l++;
		else
			l--;
		m = max(-l, m);
	}
	for (int i = 0; i < m; i++) printf("(");
	for (int i = 0; i < n; i++) printf("%c", s[i]);
	for (int i = 0; i < l + m; i++) printf(")");
	printf("\n");
	return 0;
}