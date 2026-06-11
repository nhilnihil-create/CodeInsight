#include <iostream>
#include <cstdio>
#include <map>
#include <string>
//#include<con>
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51,MOD=998244353;
ll length;
ll pw[MAXN],prefix[MAXN],suffix[MAXN];
char s[MAXN],t[MAXN];
inline ll read()
{
    register ll num=0,neg=1;
    register char ch=getchar();
    while(!isdigit(ch)&&ch!='-')
    {
        ch=getchar();
    }
    if(ch=='-')
    {
        neg=-1;
        ch=getchar();
    }
    while(isdigit(ch))
    {
        num=(num<<3)+(num<<1)+(ch-'0');
        ch=getchar();
    }
    return num*neg;
}
int main()
{
    length=read(),scanf("%s%s",s,t),pw[0]=1,prefix[0]=t[0]-'a';
    for(register int i=1;i<length;i++)
    {
        pw[i]=(li)pw[i-1]*26%MOD;
        prefix[i]=(t[i]-'a'+(li)prefix[i-1]*26%MOD)%MOD;
    }
    for(register int i=length-1,j=0;i>=0;i--,j++)
    {
        suffix[i]=(suffix[i+1]+(li)pw[j]*(s[i]-'a')%MOD)%MOD;
    }
    for(register int i=0,j=length-1;i<length;i++,j--)
    {
        if(suffix[i]==prefix[j])
        {
            return printf("%d\n",(length<<1)-j-1),0;
        }
    }
    printf("%d\n",length<<1);
}