#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define siz(v) (ll)(v).size()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, x, n) for (ll i = x; i < (ll)(n); i++)
#define lb lower_bound
#define ub upper_bound
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
const ll mod = 1000000007;
const ll INF = 1000000099;
vector<ll> dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
//cin.tie(0);ios::sync_with_stdio(false);

signed main()
{
    int n, m, ans = 1000;
    cin >> n >> m;
    vector<int> nofh(m, 0), ind(n, 0);
    vector<vector<int>> v(n, vector<int>(m));
    vector<bool> use(m,true);

    rep(i, n) rep(j, m)
    {
        cin >> v[i][j];
        v[i][j]--;
        if (j == 0)
        {
            nofh.at(v[i][0])++;
        }
    }

    int mx = 0,mxi=-1;
    rep(k, m)
    {
        mx=0;
        rep(i, m)
        {
            if(mx<nofh[i]){
                mxi=i;
            }
            mx = max(mx, nofh[i]);
        }
        ans = min(ans, mx);
        
        use[mxi]=false;
        rep(i,n){   
            if(v[i][ind[i]]==mxi){
                nofh[mxi]--;
                while(ind[i]<m-1 && !use[v[i][ind[i]]])ind[i]++;
                nofh[v[i][ind[i]]]++;
            }
        }
        //cout<<ans<<endl;
    }
    cout<<ans<<endl;
}