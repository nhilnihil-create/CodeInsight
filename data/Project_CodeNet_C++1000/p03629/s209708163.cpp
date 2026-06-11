#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
#include<queue>
#include<math.h>
#define ll long long
using namespace std;
const int maxn=250000;
int l[maxn],r[maxn],tot;
int check[30]={0};
int main()
{
    char str[maxn];
    scanf("%s",str);
    int len=strlen(str);
    r[0]=len-1;
    int now=26;

    for(int i=len-1;i>=0;i--)
    {
        if(!check[str[i]-'a'])
        {
            check[str[i]-'a']=1;
            now--;
            if(now==0)
            {
                l[tot++]=i;
                r[tot]=i-1;
                now=26;
                memset(check,0,sizeof(check));
            }
        }
    }

    l[tot]=0;
    char ch;
    int last=0;
    for(int i=tot;i>=0;i--)
    {
        int now=26;
        memset(check,0,sizeof(check));
        for(int j=last;j<=r[i];j++) check[str[j]-'a']=1;
        for(int j=0;j<26;j++)
        if(!check[j])
        {
            printf("%c",j+'a');
            ch=j+'a';
            break;
        }
        for(int j=last;j<len;j++)
        if(ch==str[j])
        {
            last=j+1;
            break;
        }
    }
}