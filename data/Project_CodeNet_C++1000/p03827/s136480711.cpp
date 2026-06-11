#include <stdio.h>
 
int main() {
	int N;
	scanf("%d", &N);
	
	char arr[N];
	scanf("%s", &arr);
	
	int X = 0;
	int max = 0;
	for(int i = 0; i < N; i++) {
		if(arr[i] == 'I') {
			X++;
			if(max < X) {
				max = X;
			}
		}
		else if(arr[i] == 'D') {
			X--;
		}
	}
	
	printf("%d\n", max);
	return 0;
}