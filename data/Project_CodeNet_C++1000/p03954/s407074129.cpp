#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=5e5;
int a[N],w[N],n;
int judge(int x)
{
    for(int i=1;i<=2*n-1;i++)a[i]=w[i]>x;
    for(int i=n,j=n;i>1;i--,j++)
    {
        if(a[i]==a[i-1])return a[i]==0;
        if(a[j]==a[j+1])return a[j]==0;
    }
    return a[n]^(n&1);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=2*n-1;i++)scanf("%d",w+i);
    int l=1,r=2*n-1,mid;
    while(l<r)
    {
        mid=(l+r)>>1;
        if(judge(mid))r=mid;
        else l=mid+1;
    }
    cout<<l<<endl;
}