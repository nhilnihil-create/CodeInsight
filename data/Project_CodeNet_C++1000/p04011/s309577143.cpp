#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define gcd(a,b) __gcd(a,b)
#define ff first
#define ss second
#define p pair<int,int>
#define pb push_back
#define endl '\n'
#define w(t) ll test;cin>>test;while(test--)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(0);
#define pi acos(-1)

int main()
{
    fast;
    ll n,k,x,y;
    cin>>n>>k>>x>>y;
    ll mn=min(n,k);
    long long ans=0;
    ans+=mn*x;
    n-=k;
    if(n>0)ans+=n*y;
    cout<<ans<<endl;
}

