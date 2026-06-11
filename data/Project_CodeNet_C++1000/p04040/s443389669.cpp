#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;
int fct[200009],invfct[200009] ;
int bigmod(int a , int b)
{
    if(b==0) return 1 ;
    int x=bigmod(a,b/2) ;
    x=((x%mod) * (x%mod))%mod ;
    if(b%2) x=((x%mod) * (a%mod))%mod ;
    return x ;
}
int findpath(int x , int y , int a , int b)
{
    int k=((fct[a+b-x-y])*(invfct[a-x]%mod))%mod ;
    //cout<<"k "<<k<<" init "<<b-y<<" "<<a-x<<" "<<invfct[b-y]<<endl ;
    k=(k*(invfct[b-y]%mod))%mod ;
   // cout<<x<<" "<<y<<" final "<<a<<" "<<b<<" "<<k<<endl ;
    return k%mod ;
}
int32_t main()
{
    int n,m,a,b ; cin>>n>>m>>a>>b ;
    fct[0]=1 ; fct[1]=1 ; invfct[0]=1 ; invfct[1]=1 ;
    for(int i = 2 ; i <= n+m ; i++)
    {
        fct[i]=(i*fct[i-1])%mod ;
        invfct[i]=bigmod(fct[i],mod-2) ;
    }
    //cout<<invfct[2]<<" "<<fct[2]<<endl ;
    int p=n-a,ans=0 ;
    for(int i = b+1 ; i <= m ; i++)
    {
       // cout<<p<<" nw "<<i<<endl ;
        int k=(findpath(1,1,p,i)*findpath(p+1,i,n,m))%mod ; k%=mod ;
        //cout<<"k : "<<k<<endl ;
        ans+=k ; ans%=mod ;
    }
    cout<<ans<<endl ;
}
