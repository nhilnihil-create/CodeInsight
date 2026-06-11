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
#define repn(i, n) for (ll i = 0; i <= (ll)(n); i++)
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
const ll mod = 1000000007;
const ll INF = 1000000099;
vector<ll> dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
//cin.tie(0);
//ios::sync_with_stdio(false);

signed main()
{
    ll n, x, ans = INF*INF;

    cin >> n >> x;
    vector<ll> v(2010, INF);

    vector<ll> mncost(n, INF * INF);

    rep(i, n)
    {
        cin >> v[i];
    }


    for (int i = 0; i < n; i++)//使用回数
    {
        ll res=0;
        for(int j=0;j < n;j++)//スライム
        {
            if(i){
                mncost[j]=min(mncost[j],v[(j-i+n)%n]);
            }else{
                mncost[j]=v[j];
            }
            res+=mncost[j];
        }
        ans=min(ans,res+x*i);
    }

    cout << ans << endl;
}