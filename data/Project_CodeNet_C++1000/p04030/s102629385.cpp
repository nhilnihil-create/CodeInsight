#include <stdio.h>

int main() {
	
	char s[11];
	scanf("%s", s);
	
	char result[11];
	int index = 0;
	
	for( int i = 0; i < 11; i++){
		if(s[i] == '0'){
			result[index] = '0';
			index++;
		}
		else if(s[i] == '1'){
			result[index] = '1';
			index++;
		}
		else if(s[i] == 'B'){
			if(index > 0){
				index--;
				result [index] = '\0';
			}
		}
	}
	
	result[index] = '\0';
	
	printf("%s", result);
	
	return 0;
}