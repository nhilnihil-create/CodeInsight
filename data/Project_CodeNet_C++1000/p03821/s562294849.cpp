#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    cin>>n;
    ll a[n];
    ll b[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i] >>b[i];
    }
    ll sum =0;
    ll ans=0;
    for(int i = n-1 ; i>=0 ; i--)
    {
        a[i] = a[i] +  sum;
        ll temp =   b[i] -  ( a[i] % b[i] );
        if( temp == b[i] )
            temp =0;
        ans += temp;
        sum += temp;
    }
    cout<<ans;
}