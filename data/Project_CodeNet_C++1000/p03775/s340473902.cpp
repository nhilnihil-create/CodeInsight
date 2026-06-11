#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll n;
    cin >> n;
    vector<ll> factors;
    for(ll i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            factors.push_back(i);
            factors.push_back(n/i);
        }
    }
    sort(factors.begin(),factors.end());
    ll siz=factors.size();
    ll val=factors[siz/2];
    
    ll count=0;
    while(val)
    {
        count++;
        val/=10;
    }
    cout << count<<"\n";
}
