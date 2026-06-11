#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define rg register
#define ll long long 
#define inf 0x3f3f3f3f
inline int read()
{
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    return x*f;
}
int n;
int a[305][305],flag[305][305];
int main(){

    n=read();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            a[i][j]=read();
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
        {
            if(i==k) continue;
            for(int j=1;j<=n;j++)
            {
                if(i==j||k==j) continue;
                if(a[i][j]>a[i][k]+a[k][j])
                {
                    printf("-1\n");
                    return 0;
                }
                if(a[i][j]==a[i][k]+a[k][j])
                {
                    flag[i][j]=flag[j][i]=1;
                }
            }
        }
    ll ans=0;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(!flag[i][j])
                ans+=a[i][j];
    printf("%lld\n",ans);
    return 0;
}