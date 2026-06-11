#include <stdio.h>
int main(){
char string[30];
scanf("%s",&string);
string[5]=' ';
string[13]=' ';
printf("%s\n",&string);
return 0;
}
