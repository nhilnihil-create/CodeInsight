#include <stdio.h>
#include <string.h>

int main()
{
char str[105];
scanf("%s" , str);
char ch = ' ';

for (int i = 0; i < strlen(str); i++){
	if(str[i] == ',')
	str[i] = ch;
}
printf("%s" , str);

return 0;
	
}