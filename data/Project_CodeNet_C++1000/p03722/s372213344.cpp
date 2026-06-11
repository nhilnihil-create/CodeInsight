#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (ll i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
const long long MAX_E = 3000;
const long long MAX_V = 2000;

struct edge { ll from, to, cost; };
ll d[MAX_V];
edge es[MAX_E];
ll V, E;

bool find_negative_loop()
{
    rep(i, MAX_V) {
        d[i] = INF;
    }
    d[0] = 0;
    rep(i, V) {
        rep(j, E) {
            edge e = es[j];
            if (d[e.to] > d[e.from] + e.cost) {
                d[e.to] = d[e.from] + e.cost;
                if (i == V - 1 && e.to == V - 1) return true;
            }
        }
    }

    return false;
}
int main()
{
    cin >> V >> E;
    rep(i, E) {
        ll a, b, c;
        cin >> a >> b >> c;
        es[i] = edge{a - 1, b - 1, -c};
    }

    if (find_negative_loop()) {
        cout << "inf" << endl;
    }
    else {
        cout << -d[V - 1] << endl;
    }
    return 0;
}