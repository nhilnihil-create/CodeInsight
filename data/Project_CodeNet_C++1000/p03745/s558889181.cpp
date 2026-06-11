#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;
typedef long double ld;
typedef unsigned long long int ull;
const long long int m=pow(10,9)+7;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    vector<ll>a;
    for(ll i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        a.push_back(x);
    }
    ll res=0;
    for(ll i=0;i<n;i++)
    {
        while(i+1<n&&a[i+1]==a[i])
            i++;
        if(a[i+1]>a[i])
        {
            while(i+1<n&&a[i+1]>=a[i])
                i++;
        }
        else
        {
            while(i+1<n&&a[i+1]<=a[i])
                i++;
        }
        res++;
    }
    cout<<res<<endl;
    return 0;
}
