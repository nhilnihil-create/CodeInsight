#include <stdio.h>

int main (){
	char arr [20];
	scanf ("%[^\n]", arr);
	for (int i = 0; i < 19; i++){
		if (i == 5 || i == 13) {
			printf (" ");
			continue;
		}
	printf("%c", arr[i]);
	}
	return 0;
}