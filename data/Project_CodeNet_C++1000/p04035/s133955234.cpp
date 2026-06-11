#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define vec(x) vector<x>
#define pb push_back
#define pii pair<ll,ll>
#define vi vector<ll>
#define vii vector<pair<ll,ll>>
#define matrix(x) vector<vector<x>>
#define all(v) v.begin(),v.end()
#define mem(a,b) memset(a, b, sizeof a)
#define ff first
#define ss second
#define mp make_pair
const int INF = 1e9;
const int MOD = 1e9 + 7;
int main()
{
    ll n,l;
    cin>>n;
    cin>>l;
    ll a[n];
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    map<ll,ll>mymap;
    ll cont=1;
    ll flag=0;
    ll k;
   for(ll i=0;i<n-1;i++)
   {
       ll total=a[i]+a[i+1];
       if(total>=l)
       {flag=1;
        k=i; break;}
        mymap.insert(pair<ll,ll>(total,cont) );
        cont++;
   }
   if(flag==1)
   {   cout<<"Possible"<<endl;
       for(ll i=0;i<k;i++)
       {cout<<i+1<<endl;}
        for(ll i=n-2;i>=k;i--)
        {cout<<i+1<<endl;}
   }
   else
    cout<<"Impossible"<<endl;
}
