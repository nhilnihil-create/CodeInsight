#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
#include <numeric>
#include <functional>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define exrep(i, a, b) for(ll i = a; i <= b; i++)
#define out(x) cout << x << endl
#define exout(x) printf("%.10f\n", x)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define re0 return 0
const ll mod = 1000000007;
const ll INF = 1e16;

int main() {
    ll n, k;
    cin >> n >> k;
    
    vvl G(n);
    vl a(n-1), b(n-1);
    rep(i, n-1) {
        cin >> a[i] >> b[i];
        a[i]--;  b[i]--;
        G[a[i]].pb(b[i]);
        G[b[i]].pb(a[i]);
    }

    ll ans = INF;
    if(k%2 == 0) {
        rep(root, n) {

            vl dist(n, -1);  // dist[v] : 頂点vの根からの距離
            queue<ll> Q;
            dist[root] = 0;
            Q.push(root);
            while(!Q.empty()) {
                ll v = Q.front();  Q.pop();
                for(ll u : G[v]) {
                    if(dist[u] == -1) {
                        dist[u] = dist[v] + 1;
                        Q.push(u);
                    }
                }
            }

            ll cnt = 0;
            rep(v, n) {
                if(dist[v] > k/2) {
                    cnt++;
                }
            }

            chmin(ans, cnt);
        }
    }
    else if(k%2 == 1) {
        rep(i, n-1) {
            
            vl dist(n, -1);  // dist[v] : 頂点vの辺iからの距離
            queue<ll> Q;
            dist[a[i]] = 0;  dist[b[i]] = 0;
            Q.push(a[i]);  Q.push(b[i]);
            while(!Q.empty()) {
                ll v = Q.front();  Q.pop();
                for(ll u : G[v]) {
                    if(dist[u] == -1) {
                        dist[u] = dist[v] + 1;
                        Q.push(u);
                    }
                }
            }

            ll cnt = 0;
            rep(v, n) {
                if(dist[v] > k/2) {
                    cnt++;
                }
            }

            chmin(ans, cnt);
        }
    }
    
    out(ans);
    re0;
}