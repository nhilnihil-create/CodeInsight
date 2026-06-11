#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define maxn 200010
using namespace std;
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch-'0'<0||ch-'0'>9){if(ch=='-') f=-1;ch=getchar();}
    while(ch-'0'>=0&&ch-'0'<=9){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n;
int a[maxn],b[maxn];
int f[maxn];
int s[maxn],top;
bool check(int x)
{
    for(int i=1;i<=2*n-1;i++)  f[i]=(a[i]>=x);
    f[0]=f[2*n]=-1;
    top=0;
    for(int i=1;i<=2*n-1;i++)
    {
        if(f[i]!=f[i-1]&&f[i]!=f[i+1])  s[++top]=i;
    }
    for(int i=1;i<=top;i++)
    {
        int l=i,r=i;
        while(s[r+1]==s[r]+1&&r<top)  r++;
        i=r;
        l=s[l];r=s[r];
        if(l==1)
        {
            if((r-l+1)&1){
                int a1=f[1],a2=(f[1]^1);
                for(int j=1;j<=(r+1)/2;j++)  f[j]=a1;
                for(int j=(r+1)/2+1;j<=r;j++)    f[j]=a2;
            }
            else{
                int a1=f[1];
                for(int j=1;j<=r;j++)  f[j]=a1;
            }
            continue;
        }
        if(r==2*n-1)
        {
            if((r-l+1)&1){
                int a1=f[2*n-1],a2=(f[2*n-1]^1);
                for(int j=2*n-1-(r-l+1)/2;j<=2*n-1;j++)  f[j]=a1;
                for(int j=l;j<=l+(r-l+1)/2-1;j++)    f[j]=a2;  
            }
            else{
                int a1=f[2*n-1];
                for(int j=l;j<=r;j++)  f[j]=a1;
            }
            continue;
        }
        if((r-l+1)&1){
            int a1=(f[l]^1);
            for(int j=l;j<=r;j++)  f[j]=a1;
        }
        else{
            int a1=(f[l]^1),a2=(f[r]^1);
            for(int j=l;j<=l+(r-l+1)/2-1;j++) f[j]=a1;
            for(int j=l+(r-l+1)/2;j<=r;j++)   f[j]=a2;
        }
    }
    return f[n];
}
int ans;
int main()
{
    n=read();
    for(int i=1;i<=2*n-1;i++)   a[i]=read();
    for(int i=1;i<=2*n-1;i++)   b[i]=a[i];
    sort(b+1,b+2*n);
     int l=1,r=2*n-1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(check(b[mid]))
        {
            l=mid+1;
            ans=mid;
        }
        else  r=mid-1;
    }
    printf("%d\n",b[ans]);
    return 0;
}