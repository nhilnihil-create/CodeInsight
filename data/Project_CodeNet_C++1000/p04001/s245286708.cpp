#include<bits/stdc++.h>
#define int long long
using namespace std;
string s ;
int n,ans=0,a[11][11] ;
int fun(int k)
{
    //cout<<k<<endl ;
    if(k<=1) return 1 ;
    int as=0 ;
    for(int i = 0 ; i < k ; i++)
    {
        //cout<<k-1<<" "<<i<<" "<<a[k-1][i]<<endl ;
        as+=(a[k-1][i]) ;
    }
    //cout<<k<<" "<<as<<endl ;
    return as ;
}
int32_t main()
{
    a[0][0] = 1 ;
    for(int i = 0 ; i <= 10 ; i++)
    {
        for(int j = 0 ; j <= 10 ; j++)
        {
            if(j == 0) a[i][j] = 1 ;
            else if(j == i) a[i][j] = 1 ;
            else if(i < j) a[i][j] = 0 ;
            else a[i][j] = a[i-1][j-1] + a[i-1][j] ;
        }
    }
    cin>>s ; n=s.size() ;
    for(int i = 0 ; i < n ; i++)
    {
        int x=0 ;
        for(int j = i ; j < n ; j++)
        {
            //cout<<i<<" "<<j<<endl ;
            int k=n-j-1,p=i ; x=(x*10)+(s[j]-'0') ;
            int pp=fun(k),q=fun(p) ;
            ans+=(pp*q*x) ;
        }
    }
    cout<<ans<<endl ;
}
