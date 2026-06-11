#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define vi vector<ll>
#define pb push_back
#define F first
#define S second
#define all(v) (v).begin(),(v).end()
#define pii pair<ll,ll>
#define vii vector<pii>
#define MOD 1000000007LL
#define calc_fact(n) tgamma(n+1)
#define INF LONG_LONG_MAX

signed main()
{
    FIO;
    ll n,a,sum=0,val1=0,val2=0,ans1=0,ans2=0;
    cin>>n;
    vi v;
    for(ll i=0;i<n;i++)
    {
        cin>>a;
        v.pb(a);
        sum+=a;
    }
    val1=ceil(((double)sum)/n);
    val2=floor(((double)sum)/n);
    for(auto it:v)
    {
        ans1+=(abs(val1-it)*abs(val1-it));
        ans2+=(abs(val2-it)*abs(val2-it));
    }
    cout<<min(ans1,ans2);
}