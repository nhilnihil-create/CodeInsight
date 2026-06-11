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


int main()
{
    ll n;cin>>n;
    while(n)
    {
        ll x=n%10;
        if(x==9)
        {
            cout<<"Yes"<<"\n";return 0;
        }
        n/=10;
    }
    cout<<"No"<<"\n";
    return 0;
}