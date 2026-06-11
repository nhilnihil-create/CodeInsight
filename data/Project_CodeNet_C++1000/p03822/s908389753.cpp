// Sakhiya07 - Yagnik Sakhiya
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define ld long double
#define ff first
#define ss second
#define pb push_back
#define all(x) x.begin(),x.end()
#define pll pair<ll,ll>
#define mp make_pair
#define bp __builtin_popcountll
#define MOD  1000000007
const int N = 100005;
#define FAST ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);srand(time(NULL));

vector<ll> v[N];
ll ans[N];
void dfs(ll id,ll p1)
{
    ll cnt = 0;
    ll s = 0;
    vector<ll> v1;
    for(auto X:v[id])
    {
        if(X!=p1)
        {
            cnt++;
            dfs(X,id);
            v1.pb(ans[X]);
        }
    }
    sort(all(v1));
    for(auto X:v1)
    {
        s = max(s,X+cnt);
        cnt--;
    }
    ans[id] = s;
}
void solve()
{
    ll n;
    cin >> n;
    for(ll i=2,x;i<=n;i++)
    {
        cin >> x;
        v[x].pb(i);
        v[i].pb(x);
    }
    dfs(1,0);
    cout<<ans[1];
}

int main()
{
    FAST;
    ll t = 1;
   // cin >> t;
    while(t--)
    {
        solve();
    }
}