#include <stdio.h>

int main(){
	int N, max = 0, x = 0;
	scanf("%d", &N);
	char s[N];
	scanf("%s", s);

	for(int i = 0; s[i] != '\0'; i++){
		if(s[i] == 'I'){
			x ++;
		}else if(s[i] == 'D'){
			x --;
		}if(max < x){
			max = x;
		}
	}
	printf("%d\n", max);
	return 0;
}