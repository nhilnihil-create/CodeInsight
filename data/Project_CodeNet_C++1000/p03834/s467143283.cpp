#include <stdio.h>
int main (){
	char str [20];
	scanf ("%s", str);
	 for (int i = 0; i < 19; i++) {
    if (i == 5 || i == 13) {
        printf(" ");
        continue;
    }
    printf("%c", str[i]);
	}
    
	puts("");
    
	return 0;
    }