#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	char s[n+1];
	scanf("%s", s);
	int x = 0, max = 0;
	for(int i = 0; s[i] != '\0'; i++){
		if(s[i] == 'I'){
			x++;
		}else if(s[i] == 'D'){
			x--;
		}
		if (max < x){
			max = x;
		}
	}
	printf("%d\n", max);
	return 0;
}
