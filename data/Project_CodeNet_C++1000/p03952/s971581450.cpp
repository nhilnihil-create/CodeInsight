#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=5e5;
int n,x,a[N],p[N];
int main()
{
    scanf("%d%d",&n,&x);n=2*n-1;
    if(x==1||x==n){puts("No");return 0;}
    puts("Yes");
    if(n==3)
    {
        cout<<1<<endl<<2<<endl<<3<<endl;
        return 0;
    }
    if(x==2)
    {
        a[n/2+1]=2;a[n/2]=1;a[n/2-1]=n;a[n/2+2]=3;
        p[2]=p[1]=p[n]=p[3]=1;
    }
    else if(x==n-1)
    {
        a[n/2+1]=n-1;a[n/2]=n;a[n/2-1]=1;a[n/2+2]=n-2;
        p[n]=p[n-1]=p[1]=p[n-2]=1;
    }
    else 
    {
        a[n/2+1]=x;a[n/2]=x-1;a[n/2-1]=x+1;a[n/2+2]=x+2;
        p[x]=p[x-1]=p[x+1]=p[x+2]=1;
    }
    int j=1;
    for(int i=1;i<=n;i++)
    {
        if(a[i])continue;
        while(p[j])++j;
        a[i]=j,++j;
    }
    for(int i=1;i<=n;i++)printf("%d\n",a[i]);
}