#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;

struct Link {
    int from, to;
    ll cost;
    Link(int f, int t, ll c) {
        from = f;
        to = t;
        cost = c;
    }  
};

const ll INF = -(1e15);

// input
int N, M;
vector<int> A, B, C;

vector<Link> links;
vector<ll> cost;


void input() {
    cin >> N >> M;
    A = B = C = vector<int>(M);
    rep(i, M) cin >> A[i] >> B[i] >> C[i];
}


bool bellman_ford() {
    cost = vector<ll>(N, INF);
    ll a, b;
    cost[0] = 0;
    rep(i, N - 1) {
        for (Link x : links) {
            if (cost[x.from] != INF) {
                cost[x.to] = max(cost[x.to], cost[x.from] + x.cost);
            }
        }
    }
    a = cost[N - 1];
    rep(i, N - 1) {
        for (Link x : links) {
            if (cost[x.from] != INF) {
                cost[x.to] = max(cost[x.to], cost[x.from] + x.cost);
            }
        }
    }
    b = cost[N - 1];
    if (a < b) return true;
    else return false;
}


int main() {
    input();
    rep(i, M) links.push_back(Link(A[i] - 1, B[i] - 1, C[i]));
    if (bellman_ford()) {
        cout << "inf" << endl;
        return 0;
    }
    ll ans = cost[N - 1];
    cout << ans << endl;
}
