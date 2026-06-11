#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n , c,k;
    cin>>n>>c>>k;
    ll t[n];
    for(int i=0;i<n;i++)
    {
        cin>>t[i];
    }
    sort( t , t+n);
    int index =0;
    ll ans =0;
    while( index < n)
    {
        ll curr = t[index];
        ll cap =1;
        while( curr + k >= t[index] && cap <= c  && index<n )
        {
           
            index++;
            cap++;
        }
        ans++;
    }
    cout<<ans;
}