
#pragma GCC optimize ("O3")

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include <prettyprint.hpp>
#define debug(...)  cerr << "[" << #__VA_ARGS__ << "]: ", d_err(__VA_ARGS__);
#else
#define debug(...) 83;
#endif

void d_err() {
    cerr << endl;
}

template <typename H, typename... T>
void d_err(H h, T... t) {
    cerr << h << " ";
    d_err(t...);
}

#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define bcnt __builtin_popcountll

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll,ll> Pll;
typedef pair<int,int> Pin;

ll INF = 1e16;
int inf = 1e9;
ll MOD = 1e9+7;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    
    ll N, W;
    cin >> N >> W;


    map<ll, vector<ll>> I;
    REP(i, N) {
        ll w, v;
        cin >> w >> v;
        I[w].pb(v);
    }

    unordered_map<ll, ll> m;
    m[0] = 0;
    for (auto it=I.begin(); it!=I.end(); it++) {
        sort(it->se.begin(), it->se.end(), greater<ll>());

        ll w = it->fi;

        REP(i, it->se.size()) {
            unordered_map<ll, ll> tmp;
            ll v = it->se[i];
            for(auto j=m.begin(); j!=m.end(); ++j) {
                ll nw = j->fi + w;
                if (m.find(nw) != m.end()) tmp[nw] = max(j->se + v, m[nw]);
                else tmp[nw] = j->se + v;
            }

            for(auto j=tmp.begin(); j!= tmp.end(); ++j) {
                m[j->fi] = max(m[j->fi], j->se);
            }
        }
    }

    ll ans = 0;
    for(auto it=m.begin(); it!=m.end(); ++it) {
        if(it->fi > W) continue;
        ans = max(ans, it->se);
    }

    cout << ans << endl;
    
}
