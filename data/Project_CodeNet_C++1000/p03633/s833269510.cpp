// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")

#include <bits/stdc++.h>  
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define pl pair<ll,ll>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define vl vector<ll>
#define N 100005
#define mod 1000000007

ll lcm(ll a,ll b)
{
    return a/__gcd(a,b)*b;
}

int main()
{   
    ll n;cin>>n;
    ll a[n];
    ll sol=1;
    for(ll i=0;i<n;i++)
    cin>>a[i];
    for(ll i=0;i<n;i++)
    {
        sol=lcm(sol,a[i]);
    }
    cout<<sol<<"\n";
    return 0;
}