#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n;
int val[maxn],sor[maxn],tag[maxn];
bool check(int v)
{
    for(int i=1;i<=2*n-1;i++)tag[i]=val[i]>=v;
    int dis1=1<<30,col1=0;
    int dis2=1<<30,col2=0;
    for(int i=n;i>=2;i--)
    if(tag[i]==tag[i-1])
    {
        dis1=n-i,col1=tag[i];
        break;
    }
    for(int i=n;i<=2*n-2;i++)
    if(tag[i]==tag[i+1])
    {
        dis2=i-n,col2=tag[i];
        break;
    }
    if(dis1==dis2&&dis1==(1<<30))return ((n-1)&1)^tag[n];
    return dis1<dis2?col1:col2;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=2*n-1;i++)scanf("%d",&val[i]),sor[i]=val[i];
    sort(sor+1,sor+2*n);
    int l=1,r=2*n-1,ans=1;
    while(l<=r)
    {
        int mid=l+r>>1;
        if(check(sor[mid]))l=mid+1,ans=mid;
        else r=mid-1;
    }
    printf("%d\n",sor[ans]);
}