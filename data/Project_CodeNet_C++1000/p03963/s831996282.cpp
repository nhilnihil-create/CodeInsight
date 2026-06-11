#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,ans=1,k;
    cin>>n>>k;
    ans=k;                         //for first ball we have k different options
    for(int i=2;i<=n;i++)
    {
        ans*=(k-1);        //for remaining balls we have k-1 options
    }
    cout<<ans<<endl;
    return 0;
}