#include <stdio.h>
#include <string.h>
int main() {
	char a[255];
	
	scanf("%s", a);
	
	int len = strlen(a);
	
	for(int i = 0; i < len; i++) {
		
		int sum = 0;
		
		if(a[i] == 'B' && i != 0) {
			int j = i;
			int k = 1;
			
		while(a[j] == 'B') {
			a[i-k] = 'B';
			k++;
			j++;
		}
		
		sum++;
		}
	}
	for(int i = 0; i < len; i++) {
		
		if(a[i] != 'B') {
			printf("%c", a[i]);
		}
	}
	
	return 0;
	
}
