#include<stdio.h>
#include<string.h>

char inp[16];

int main (void) {
	int m, n, i, j, ox, oy;
	scanf(" %d %d", &m, &n);
	for(i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			scanf(" %s", &inp);
			if(!strcmp(inp, "snuke")) {
				ox = i;
				oy = j;
				goto prre;
			}
		}
	}

	prre:
	printf("%c%d\n", 'A' + oy, ox + 1);
	
	return 0;
}