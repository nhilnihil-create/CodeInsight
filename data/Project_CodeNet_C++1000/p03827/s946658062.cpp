#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	char str[100];
	scanf("%s", str);

	int ans[n];
	int x = 0;
	for (int i=0; i<n; i++){
		if (str[i] == 'I'){
			x++;
			ans[i] = x;
		}
		if (str[i] == 'D'){
			x--;
			ans[i] = x;
		}
	}

	int max = 0;
	for (int i=0; i<n; i++){
		if (max < ans[i]){
			max = ans[i];
		}
	}

	printf("%d\n", max);

	return 0;
}
