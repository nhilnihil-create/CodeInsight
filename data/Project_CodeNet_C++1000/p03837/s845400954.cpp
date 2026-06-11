#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i) 
#define PI acos(-1)
#define pcnt __builtin_popcountll
#define rng(a) a.begin(), a.end()
#define sz(x) (int)(x).size()
#define v(T) vector<T>
#define vv(T) v(v(T))
#define fi first
#define se second

using namespace std;
using ll = long long;
using P = pair<int, int>;
using LP = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

template<typename T>inline istream& operator>>(istream&i,v(T)&v)
{rep(j,sz(v))i>>v[j];return i;}
template<typename T1,typename T2>inline istream& operator>>(istream&i,pair<T1,T2>&v)
{return i>>v.fi>>v.se;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) {if (a > b) { a = b; return true; } return false; }

ll INF = 1001001001;
ll LINF = 1001001001001001001ll;

using tl = tuple<ll, ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n, m;
    cin>>n>>m;
    vector<vector<tl>> to(n);
    rep(i, m) {
        ll a, b, c;
        cin>>a>>b>>c; a--; b--;
        to[a].emplace_back(b, c, i);
        to[b].emplace_back(a, c, i);
    }

    vector<bool> used(m);
    rep(i, n) {
        vector<ll> visited(n, LINF);
        priority_queue<tl, vector<tl>, greater<tl>> q;
        q.emplace(0, i, -1);
        while (!q.empty()) {
            tl t = q.top(); q.pop();
            ll d = get<0>(t);
            ll v = get<1>(t);
            ll e = get<2>(t);
            if (visited[v] != LINF) {
                if (visited[v] == d && e != -1) {
                    used[e] = true;
                }
                continue;
            }

            visited[v] = d;
            if (e != -1) used[e] = true;
            for (auto nt : to[v]) {
                ll nv = get<0>(nt);
                ll nd = get<1>(nt) + d;
                ll ne = get<2>(nt);
                q.emplace(nd, nv, ne);
            }
        }
    }
    ll ans = 0;
    rep(i, m) if(!used[i]) ans++;
    cout<<ans<<endl;
}