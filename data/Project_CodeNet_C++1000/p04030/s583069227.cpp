#include <stdio.h>

int main() {
	char str[20], newStr[20] = {};
	scanf("%s", str);
	int j = 0;
	
	for(int i = 0; str[i] != '\0'; i++) {
		if(str[i] == '1') {
			newStr[j] = '1';
			j++;
		} else if(str[i] == '0') {
			newStr[j] = '0';
			j++;
		} else if(j != 0) {
			if(str[i] == 'B') {
				newStr[j - 1] = '\0';
				j -= 2;
			}
			j++;
		}
	}
	newStr[j] = '\0';
	printf("%s", newStr);
	
	return 0;
}