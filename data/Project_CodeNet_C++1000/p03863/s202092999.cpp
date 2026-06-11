#include<bits/stdc++.h>
using namespace std;
int len;
char s[100005];
int main()
{
    cin>>s;
    len=strlen(s);
    if(s[0]==s[len-1])
    {
        if(len%2==0)
            printf("First\n");
        else
            printf("Second\n");
    }
    else
    {
        if(len%2==0)
            printf("Second\n");
        else
            printf("First\n");
    }
    return 0;
}