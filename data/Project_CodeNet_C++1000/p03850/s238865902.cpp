#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 200010
using namespace std;
typedef long long ll;
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch-'0'<0||ch-'0'>9){if(ch=='-') f=-1;ch=getchar();}
    while(ch-'0'>=0&&ch-'0'<=9){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int T,n;
char op[200010];
ll a[maxn];
int top;
void merge()
{
    top=0;
    a[++top]=a[1];
    op[0]='+';
    for(int i=2;i<=n;i++)
    {
        if(op[i-1]=='+'&&op[top-1]=='+')  a[top]+=a[i];
        else{
            op[top]=op[i-1];
            a[++top]=a[i];
        }
    }
    n=top;
}
ll sum[maxn],f[maxn];
int main()
{
        n=read();
        for(int i=1;i<=2*n-1;i++)
        {
            if(i&1)  a[(i+1)/2]=read();
            else{
                char s[3];
                scanf("%s",s);
                op[i/2]=s[0];
            }
        }
        merge();
        sum[n+1]=0;
        for(int i=n;i>=1;i--)  sum[i]=sum[i+1]+a[i];
        f[n]=a[n];
        for(int i=n-1;i>=1;i--)
        {
            if(op[i]=='+')  f[i]=f[i+1]+a[i];
            else{
                if(i==n-1)
                {
                    f[i]=a[i]-a[i+1];
                    continue;
                }
                else{
                    if(op[i+1]=='-')  f[i]=a[i]-a[i+1]+sum[i+2];
                    else              f[i]=max(a[i]-a[i+1]+f[i+2],a[i]-a[i+1]-a[i+2]+sum[i+3]);
                }
            }
        }
        printf("%lld\n",f[1]);
    return 0;
}