#include <stdio.h>
#include <string.h>

int main () {
	char s[101];
	int i;
	scanf ("%[^\n]", s);
	int pnjg = strlen (s);
	for (int i = 0; i < pnjg ; i++) {
		if (s[i] == ',') {
			s[i] = ' ';
		}
	}
	printf ("%s", s);
	
	return 0;
}