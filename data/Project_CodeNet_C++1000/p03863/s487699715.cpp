#include<stdio.h>
#include<string.h>
char s[1000010];int main(){int len;scanf("%s",s);len=strlen(s);return 0&printf("%s",((s[0]==s[len-1])^(len%2))?"First":"Second");}