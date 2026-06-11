#include<cstdio>
#include<cstring>
using namespace std;
char s[10001];
int main()
{
    gets(s);
    for(int i=0;i<strlen(s);i++)
    {
        printf("%c",s[i]);
        if(i==3)
        printf(" ");
    }
    printf("\n");
    return 0;
}