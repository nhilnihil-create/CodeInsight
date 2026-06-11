#include <stdio.h>
#include <string.h>

#define INT_MAX 2147483647
#define INT_MIN -2147483648

int max(int a, int b);
int min(int a, int b);
int abs(int a);

int main() {
	int n;
	char s[105];

	scanf("%d", &n);
	scanf("%s", s);

	int maxi = 0;
	int curr = 0;
	for(int i = 0; i < n; i++) {
		if(s[i] == 'D') {
			curr--;
		}
		else if(s[i] == 'I'){
			curr++;
		}
		maxi = max(maxi, curr);
	}

	printf("%d\n", maxi);
	return 0;
}

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;	
}

int max(int a, int b) {
	return (a > b) ? a : b;
}

int min(int a, int b) {
	return (a < b) ? a : b;
}

int abs(int a) {
	return (a < 0) ? -a : a;
}
