#include<stdio.h>
#include<stdlib.h>

long int value(long int a, long int b) {
	if (a > b) {
		return a - b;
	}
	else {
		return b - a;
	}
}

int main() {
	int n;
	long int temp = 0;
	long int sum1 = 0;
	long int sum = 0;
	long int min = 2e+9;
	scanf("%d", &n);
	
	long int *a;
	a = (long int *)malloc(n * sizeof(long int));
	 
	for (int i = 0; i < n; i++) {
		scanf("%ld", &a[i]);
		sum += a[i];
	}
	for (int i = 0; i < n - 1; i++) {
		sum1 += a[i];
		temp = value(2 * sum1, sum);
		if (temp < min) {
			min = temp;
		}
	}
	printf("%ld", min);
	return 0;
}