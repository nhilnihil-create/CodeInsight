#include <stdio.h>

int main()
{
    char s[15];
    scanf("%s",s);
    bool judge=true;
    if(s[0]=='Y'&&s[1]=='A'&&s[2]=='K'&&s[3]=='I')
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    
}