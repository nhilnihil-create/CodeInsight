#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, N) for (int i = 0; i < (N); ++i)

int N;
vector<int> graph[100100];

int grundy(int cur, int prv = -1) {
    int ret = 0;
    for (auto& nxt: graph[cur]) {
        if (nxt == prv) continue;
        ret ^= grundy(nxt, cur) + 1;
    }
    return ret;
}

signed main() {
    cin >> N;
    REP(i, N - 1) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }
    if (grundy(0)) cout << "Alice" << endl;
    else cout << "Bob" << endl;
}
