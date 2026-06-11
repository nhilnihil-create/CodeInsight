#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<ll>> G;

ll solve() {
    ll N;
    cin >> N;
    vector<vector<int>> G(N);
    int a, b;
    for ( int i = 0; i < N-1; i++ ) {
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<int> num(3);
    vector<int> used(N); // b:1, w:2
    queue<int> q;
    q.push(0);
    used[0] = 1;
    num[1]++;
    q.push(N-1);
    used[N-1] = 2;
    num[2]++;
    while ( !q.empty() ) {
        int p = q.front();
        q.pop();
        for ( int v : G[p] ) {
            if ( used[v] == 0 ) {
                int c = used[p];
                used[v] = c;
                num[c]++;
                q.push(v);
                if ( num[c] > N / 2 ) return c;
            }
        }
    }
    if ( N & 1 ) return 1;
    else return 2;
    return 0;
}

int main() {
    auto ans = solve() == 1 ? "Fennec" : "Snuke";
    cout << ans << "\n";
    return 0;
}