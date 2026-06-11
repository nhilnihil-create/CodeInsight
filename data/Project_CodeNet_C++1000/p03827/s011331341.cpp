#include <stdio.h>

int main () {
	char string[105], x = 0, n;
	scanf("%d\n", &n);
	scanf("%s", string);
	
	int temp = x;
	for(int i = 0; i < n; i++) {
		if(string[i] == 'I') {
			x++;
			if (temp <= x) {
				temp = x;
			}
		}
		else if (string[i] == 'D') {
			x--;
			if (temp <= x) {
				temp = x;
			}
		}
	}
	printf("%d", temp);
	
	
	return 0;
}