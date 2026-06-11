#include <stdio.h>

int main() {
	int x, a, b;
	scanf ("%d%d%d", &x, &a, &b);
	int xa = x - a;
	int xb = x - b;
	
	if (xa < 0) {
		xa *= -1;
		if (xb< 0) {
			xb *= -1;
			xa > xb ? printf ("B\n") : printf ("A\n");
		}
		else {
			xa > xb ? printf ("B\n") : printf ("A\n");
		}
	}
	else if (xb < 0) {
		xb *= -1;
		if (xa< 0) {
			xa *= -1;
			xa > xb ? printf ("B\n") : printf ("A\n");
		}
		else {
			xa > xb ? printf ("B\n") : printf ("A\n");
		}
	}
	else {
		xa > xb ? printf ("B\n") : printf ("A\n");
	}
	return 0;	
}