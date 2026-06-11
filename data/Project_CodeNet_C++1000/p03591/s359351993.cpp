#include<stdio.h>
int main(void) {
	char s[11];
	int i = 0;
	scanf("%s", s);
	if (s[i] == 'Y') {
		if (s[i+1]  == 'A') {
			if (s[i + 2] == 'K') {
				if (s[i + 3] == 'I') {
					printf("Yes\n");
				}
				else {
					printf("No\n");
				}
			}else printf("No\n");
		}else printf("No\n");
	}else printf("No\n");
	return 0;
}