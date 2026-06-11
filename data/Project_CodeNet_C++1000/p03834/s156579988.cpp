#include <stdio.h>
int main(){
	char inp[20];
	scanf("%s", &inp);
	inp[5]=' ';
	inp[13]=' ';
	printf("%s", inp);
	return 0;
}