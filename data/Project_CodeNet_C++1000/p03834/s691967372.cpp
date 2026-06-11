#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
    char s[20];
    scanf("%s",s);
    int l=strlen(s);
    int i;
    for(i=0; i<l ; i++)
    {
        if(s[i]==',') s[i]=' ';
    }
    printf("%s\n",s);

}
