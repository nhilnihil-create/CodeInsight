#include<iostream>
#include<string>
#include<string.h>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
using namespace std;
int n,l,t,pos[100100],rk=0;

int read()
{
    int x=0,f=1;char ch=getchar();
    while ((ch<'0') || (ch>'9')) {if (ch=='-') f=-1;ch=getchar();}
    while ((ch>='0') && (ch<='9')) {x=x*10+(ch-'0');ch=getchar();}
    return x*f;
}

int main()
{
    n=read();l=read();t=read();int i;
    for (i=1;i<=n;i++)
    {
        int now=read(),face=read();
        if (face==1)
        {
            pos[i]=(now+t)%l;
            rk+=((now+t)/l);
        }
        else if (face==2)
        {
            pos[i]=(now-t)%l;
            if (pos[i]<0) {pos[i]+=l;rk--;}
            rk+=(now-t)/l;
        }
    }
    sort(pos+1,pos+1+n);
    rk=(rk%n+n)%n;
    for (i=rk+1;i<=n;i++) printf("%d\n",pos[i]);
    for (i=1;i<=rk;i++) printf("%d\n",pos[i]);
    return 0;
}