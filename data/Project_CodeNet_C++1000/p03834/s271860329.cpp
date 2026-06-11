#include <stdio.h>

int main() {
	char str[255];
	scanf("%s", str);
	// happy,newyear, enjoy
	str[5] = ' '; // karakter ke 6 pasti koma
	str[13] = ' '; // karakter ke 14 pasti koma
	printf("%s\n", str);
	return 0;
}