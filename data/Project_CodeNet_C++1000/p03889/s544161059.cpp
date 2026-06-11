#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
char s[maxn];
int main()
{
    int len,flag=1;
    scanf("%s",s+1);
    len=strlen(s+1);
    int head=1,tail=len;
    for(int i=1;i<=len;i++)
    {
        char n;
        if(s[tail]=='b')n='d';
        else if(s[tail]=='d')n='b';
        else if(s[tail]=='p')n='q';
        else if(s[tail]=='q')n='p';
        if(n!=s[head])
        {
            flag=0;
            break;
        }
        head++;
        tail--;
    }
    if(flag)
    printf("Yes");
    else
    printf("No");
    return 0;
}