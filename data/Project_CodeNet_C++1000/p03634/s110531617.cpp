#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main(){
    int N;
    cin >> N;
    vector<vector<pll> > G(N, vector<pll>());
    ll a, b, c;
    for (int i = 0; i < N-1; i++) {
        cin >> a >> b >> c;
        a--, b--;
        G[a].push_back(pii(b, c));
        G[b].push_back(pii(a, c));
    }
    int Q, K;
    cin >> Q >> K;
    K--;
    queue<int> q;
    vector<ll> d(N, -1);
    q.push(K);
    d[K] = 0;
    while (!q.empty()) {
        int from = q.front();
        q.pop();
        for (pll p : G[from]) {
            int to = p.first;
            ll w = p.second;
            if (d[to] != -1) continue;
            d[to] = d[from] + w;
            q.push(to);
        }
    }
    for (int i = 0; i < Q; i++) {
        cin >> a >> b;
        a--, b--;
        cout << d[a] + d[b] << '\n';
    }
}
