#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main(void)
{
	char s[30][30][9];
	int h, w,i,j;
	scanf("%d %d", &h, &w);
	for (i = 0; i < h; i++) {
		for (j = 0; j < w; j++) {
			scanf("%s", s[i][j]);
		}
	}
	
	for (i = 0; i < h; i++) {
		for (j = 0; j < w; j++) {
			if (strcmp(s[i][j], "snuke") == 0) {
				printf("%c%d\n", 'A' + j, i + 1);
			}
		}
	}

	return 0;
}