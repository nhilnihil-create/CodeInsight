//bad_bat
#include<bits/stdc++.h>
using namespace std;

#define Fast ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0)
#define FO freopen("in.txt", "r", stdin)
#define FC freopen("out.txt", "w", stdout)
#define aise cout<<"aise"<<endl
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define mp make_pair
#define ll long long
#define all(x) x.begin(), x.end()
#define mset(v, a) memset(v, a, sizeof(v))
#define pll pair< ll, ll >
#define pdd pair< double, double >
#define ff first
#define ss second
#define pi acos(-1.0)
#define mxN 2010
#define inf 1e14
#define mod 1000000007

int main()
{

    ll n,t, l,r,ans=0;
    cin >> n >> t;
    vector<ll> v;
    for(ll i=0; i < n; i++)
    {

        ll x;
        cin >> x;
        v.pb(x);
    }
    l = 0, r=t;
    for(ll i=1; i < v.size(); i++)
    {

        ll cl=v[i], cr=v[i]+t;
        if(cl > r)
        {

            ans+=(r-l);
            l=cl, r=cr;
        }
        else if(cr <= r) continue;
        else r=cr;
    }
    ans+=(r-l);
    cout << ans;
}
