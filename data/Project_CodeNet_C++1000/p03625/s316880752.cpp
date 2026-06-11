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
#define MOD 1000000007

ll dx[]={0,0,1,-1,1,1,-1,-1};
ll dy[]={1,-1,0,0,1,-1,1,-1};

int main()
{
    ll n;
    cin >> n;
    vector<ll > v;
    map<ll,ll> m;
    for(ll i = 0; i < n; i++)
    {

        ll x;
        cin >> x;
        if(m[x]==0) v.pb(x);
        m[x]++;
    }
    sort(all(v));
    reverse(all(v));
    vector<ll> ans;
    for(ll i = 0; i < v.size(); i++)
    {
        if(ans.size() >= 2) break;
        ll x = v[i];
        if(m[x] >= 4)
        {

            ans.pb(x);
            ans.pb(x);
        }
        else if(m[x] >= 2 && m[x] <= 3) ans.pb(x);
    }
    if(ans.size() >= 2) cout << ans[0]*ans[1];
    else cout << 0;
}
