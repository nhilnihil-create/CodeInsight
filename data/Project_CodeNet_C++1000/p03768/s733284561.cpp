#include <bits/stdc++.h>
using namespace std;

#define SZ(x) (int)(x).size()
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for (int i=(a);i>=(b);--i)

const int MX_N = 1e5+5;
const int MX_Q = 1e5+5;

int N, M, Q;
vector<int> al[MX_N];

tuple<int,int,int> que[MX_Q];
int c[MX_N][11];
queue<pair<int,int>> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    FOR(i,1,M){
        int A, B; cin >> A >> B;
        al[A].push_back(B);
        al[B].push_back(A);
    }

    cin >> Q;
    FOR(i,1,Q){
        int V, D, C; cin >> V >> D >> C;
        que[i] = make_tuple(V,D,C);
    }

    RFOR(i,Q,1){
        int V, D, C; tie(V,D,C) = que[i];
        if (c[V][D] > 0) continue;
        c[V][D] = C;
        q.emplace(V,D);
        while (!q.empty()) {
            auto u = q.front(); q.pop();
            if (u.second == 0) continue;
            if (c[u.first][u.second-1] == 0) {
                c[u.first][u.second-1] = C;
                q.emplace(u.first,u.second-1);
            }
            for (int v : al[u.first]) {
                if (c[v][u.second-1] == 0) {
                    c[v][u.second-1] = C;
                    q.emplace(v,u.second-1);
                }
            }
        }
    }

    FOR(i,1,N) cout << c[i][0] << '\n';
}

