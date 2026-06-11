#include <cstdio>
#include <cstring>
char s[100003];
int main()
{
    scanf("%s",s);
    int l=strlen(s);
    if((s[0]==s[l-1])!=(l%2==0)) puts("Second");
	else puts("First");
}