#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;cin>>n;

    ll g=1;
    for(int i=0;i<n;i++)
    {
        ll t;cin>>t;
        g=lcm(g,t);
    }

    cout<<g<<"\n";

    return 0;
}
