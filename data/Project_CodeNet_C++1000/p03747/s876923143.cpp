#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 100010
using namespace std;
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch-'0'<0||ch-'0'>9){if(ch=='-') f=-1;ch=getchar();}
    while(ch-'0'>=0&&ch-'0'<=9){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,L,T;
int pos[maxn];
int main()
{
    n=read();L=read();T=read();
    int tmp=0;
    for(int i=0;i<n;i++)
    {
        int x=read(),w=read();
        if(w==1)
        {
            pos[i]=(x+T)%L;
            tmp+=(x+T)/L;
        }
        else{
            pos[i]=(x-T)%L;
            tmp+=(x-T)/L;
            if(pos[i]<0)
            {
                pos[i]+=L;
                tmp--;
            }
        }
    }
    tmp=(tmp%n+n)%n;
    sort(pos,pos+n);
    for(int i=tmp;i<n;i++)  printf("%d\n",pos[i]);
    for(int i=0;i<tmp;i++)  printf("%d\n",pos[i]);
    return 0;
}