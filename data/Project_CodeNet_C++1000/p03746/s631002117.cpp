#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define fi first
#define se second
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define siz(v) (ll)(v).size()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, x, n) for (ll i = x; i < (ll)(n); i++)
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
const ll mod = 1000000007;
const ll INF = 1000000099;
vector<ll> dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
//cin.tie(0);
//ios::sync_with_stdio(false);
vector<bool> f(100010, false);

vector<ll> dfs(ll s, vector<vector<ll>> &v)
{

    vector<ll> ans(0);
    stack<ll> st;
    st.push(s);

    while (!st.empty())
    {
        ll node = st.top();
        st.pop();

        f.at(node) = true;
        ans.pb(node);

        for (int i = 0; i < siz(v[node]); i++)
        {
            if (!f[v[node].at(i)])
            {
                st.push(v[node].at(i));
                break;
            }
        }
    }

    
    return ans;
}

signed main()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> e(n + 1, vector<ll>(0));
    rep(i, m)
    {
        ll a, b;
        cin >> a >> b;
        e.at(a).pb(b);
        e.at(b).pb(a);
    }

    ll s = 1;
    for (int i = 1; i < n + 1; i++)
    {
        if (siz(e[i]) == 1)
        {
            s = i;
            break;
        }
    }
    vector<ll> x=dfs(s, e),y=dfs(s, e);

    if(siz(y)==1){
        cout<<siz(x)<<endl;
        rep(i,siz(x)){
            cout<<x[i]<<" ";
        }
        cout<<endl;
    }else{
        cout<<siz(x)+siz(y)-1<<endl;
        for(int i=siz(y)-1;0 < i;i--)
        {
            cout<<y[i]<<" ";
        }
        rep(i,siz(x)){
            cout<<x[i]<<" ";
        }
        cout<<endl;
    }
}
