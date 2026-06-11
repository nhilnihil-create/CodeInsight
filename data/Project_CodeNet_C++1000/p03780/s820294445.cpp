#include<bits/stdc++.h>
using namespace std;
int n,k,s,a[5005];
bool f[5005]={1};
int read()
{
    int re=0;
    char ch=getchar();
    while(!isdigit(ch)) ch=getchar();
    while(isdigit(ch)) re=re*10+ch-'0',ch=getchar();
    return re;
}
int main()
{
    n=read(),k=read();
    for(int i=1;i<=n;i++) a[i]=min(k,read()),s+=a[i];
    sort(a,a+n+1);
    for(int i=n;i>=0;i--)
    {
        bool flag=true;
        for(int j=k-1;j>=max(0,k-s);j--)
            if(f[j])
            {
                flag=false;
                break;
            }
        if(flag)
        {
            printf("%d",i);
            return 0;
        }
        for(int j=a[i];j<k;j++)
            f[j]|=f[j-a[i]];
        s-=a[i];
    }
}
