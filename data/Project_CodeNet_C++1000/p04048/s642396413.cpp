#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
int main()
{
    fast;
    ll n,x; cin>>n>>x;
    ll a=n-x;
    cout<<3*(n-__gcd(n,x))<<"\n";
    return 0;
}
