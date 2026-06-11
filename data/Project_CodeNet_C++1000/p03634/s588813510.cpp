#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,ll>;
const int MAX = 100005;
vector<P> to[MAX];
vector<ll> Node(MAX);
void rec(int cur, int prev, ll d) {
    Node[cur] = d;
    for(P v : to[cur]) {
        if(v.first == prev) continue;
        rec(v.first, cur, d+v.second);
    }
}
int main() {
    int n; cin >> n;
    rep(i, n-1) {
        int a, b; ll c; cin >> a >> b >> c;
        a--; b--;
        to[a].push_back(P{b, c});
        to[b].push_back(P{a, c});
    }
    int q, k; cin >> q >> k;
    k--;
    rec(k,-1,0);
    rep(i, q) {
        int x, y; cin >> x >> y; x--; y--;
        //x to k
        ll x_k = abs(Node[x]-Node[k]);
        ll y_k = abs(Node[y]-Node[k]);
        cout << x_k + y_k << endl;
    }
}
