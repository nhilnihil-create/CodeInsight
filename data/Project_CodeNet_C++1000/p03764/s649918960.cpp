#include<iostream>
#define N 105000
#define P 1000000007
using namespace std;
int   n,m,x[N],y[N],h[N],w[N],t,tl;
long long sum,ans;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    cin>>tl;
    for(int i=1;i<n;i++)
    {
        cin>>t;
        w[i]=t-tl;
        x[i]=1LL*i*(n-i)%P;
        tl=t;
    }
    cin>>tl;
    for(int j=1;j<m;j++)
    {
        cin>>t;
        h[j]=t-tl;
        y[j]=1LL*j*(m-j)%P;
        tl=t;
    }
    for(int j=1;j<m;j++)
        sum=(sum+1LL*y[j]*h[j]%P)%P;
    for(int i=1;i<n;i++)
        ans=(ans+1LL*x[i]*w[i]%P*sum)%P;
    ans=(ans+P)%P;
    cout<<ans<<endl;
    return 0;
}