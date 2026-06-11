#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdint.h>
#include<vector>
#include<deque>
#include<string>
#include<cstring>
#include<time.h>
#include<iomanip>
#include<list>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<random>
#include<bitset>
#include <queue>
#include <map>


using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using ldouble = long double;

#define repi(i,a,b) for(ll i = (a); i < (b); i++)
#define rep(i, n) for(ll i = 0; i < (n); ++i)

ll inf = 1000000000000000000;

using P = pair<ll, ll>;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<ll> d(N);
    d[0] = 0;
    repi(i,1, N) d[i] = inf;
    vector<P> ed(M);
    vector<ll> cost(M);
    rep(i, M) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        ed[i] = P(a, b);
        cost[i] = -c;
    }
    rep(i, N) {
        rep(j, M) {
            ll from = ed[j].first;
            ll to = ed[j].second;
            if (d[from] == inf)continue;
            if (d[to] > d[from] + cost[j]) {
                d[to] = d[from] + cost[j];
                if (i == N - 1) {
                    queue<ll> q;
                    q.push(to);
                    while (!q.empty()) {
                        ll x = q.front();
                        q.pop();
                        d[x] = -inf;
                        rep(k, M) if (ed[k].first == x && d[ed[k].second] != -inf) q.push(ed[k].second);
                    }
                }
            }
        }
    }
    if (d[N - 1] == -inf) cout << "inf" << endl;
    else cout << -d[N - 1] << endl;
    return 0;
}

