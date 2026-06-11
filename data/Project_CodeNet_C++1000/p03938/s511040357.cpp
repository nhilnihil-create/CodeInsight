#include<iostream>
#include<cstdio>
using namespace std;
#define MAX 20200
inline int read()
{
    int x=0;bool t=false;char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
    if(ch=='-')t=true,ch=getchar();
    while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
    return t?-x:x;
}

int n,a[MAX],b[MAX];

int main()
{
    n=read();
    for(int i=1;i<=n;++i)a[i]=i*(n+1),b[i]=(n-i+1)*(n+1);
    for(int i=1;i<=n;++i)a[read()]-=(n-i+1);
    for(int i=1;i<=n;++i)printf("%d ",a[i]);puts("");
    for(int i=1;i<=n;++i)printf("%d ",b[i]);puts("");
}