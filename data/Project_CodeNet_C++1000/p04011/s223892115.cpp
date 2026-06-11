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
ll n,k,x,y;
cin>>n;
cin>>k;
cin>>x;
cin>>y;
ll res=n-k;
ll total;
if(res>=0)
{
    total=k*x;
    total=total+res*y;

}
else
    total=n*x;
    cout<<total<<endl;

}
