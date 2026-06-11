#include <stdio.h>

int main () {
	int N;
	scanf ("%d", &N);
	char S[N];
	scanf ("%s", S);
	
	int x = 0;
	int max = 0;
	for (int i = 0; i < N; i++) {
		if (S[i] == 'I') {
			x++;
		} else if (S[i] == 'D') {
			x--;
		}		
		if (x > max) {
			max = x;
		} 
	}
	
	printf ("%d", max);
	return 0;
}