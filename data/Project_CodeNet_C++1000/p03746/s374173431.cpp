#include<bits/stdc++.h>

using namespace std;
using ll = long long;

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define debug(x) cout << #x << ": " << x << endl;

bool ok(int node, vector<bool> used, vector<int> G[]) {
    bool flg = true;
    for (auto to : G[node]) {
        if (used[to])continue;
        flg = false;
    }
    return flg;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> G[100010];
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }

    deque<int> dq;
    vector<bool> used(N, false);
    dq.push_back(0);
    used[0] = true;
    for(auto to : G[0]){
        if(used[to])continue;
        dq.push_back(to);
        used[to]=true;
        break;
    }

    while ((!ok(dq.front(), used, G))) {
        for (auto to : G[dq.front()]) {
            if (used[to])continue;
            dq.push_front(to);
            used[to] = true;
            break;
        }
    }
    while((!ok(dq.back(), used, G))){
        for (auto to : G[dq.back()]) {
            if (used[to])continue;
            dq.push_back(to);
            used[to] = true;
            break;
        }
    }

    cout << dq.size() << endl;
    for (auto i = dq.begin(); i != dq.end(); i++) {
        if (i == dq.begin())cout << *i + 1;
        else cout << " " << *i + 1;
    }
    cout << endl;

    return 0;
}
