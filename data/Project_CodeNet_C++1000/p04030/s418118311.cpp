#include <stdio.h>
#include <string.h>

int main() {
	char s[20] = {0};
	scanf ("%s", &s);
	int slong = strlen(s);
	int d[11] = {0};
	int B=0;
	
	// CHECKING IF THERE IS A B AND CHANGIN THE 'B' CHAR TO 1 in array
	for (int i = 0; i <= slong; i++) {
		if (s[i] == 'B') {
			B++;
			continue;
		}
		else if (s[i] != 'B') {
			int del = 0;
			del = B*2;
			for (int j = 1; j <= del; j++) {
				if (i - j >= 0) {
					d[i - j] = 1;
				}
				else {
					break;
				}
			}
			B = 0;
		}
	}
	// Just print 4head
	for (int k = 0; k < slong; k++) {
		if (d[k] == 0) {
			printf ("%c", s[k]);
		}
	}

	return 0;
}