#include <bits/stdc++.h>
#define WHOLE(v) (v).begin(), (v).end()
#define REV_WHOLE(v) (v).rbegin(), (v).rend()
using i64 = int64_t;
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<set<int>> tree(N);
    for(int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        tree[a].insert(b);
        tree[b].insert(a);
    }
    vector<int> d(N, 0);
    d[0] = 1, d[N - 1] = -1;
    queue<pair<int, int>> q;
    q.push({0, 1});
    q.push({N - 1, -1});
    while(q.size()) {
        int i, c;
        tie(i, c) = q.front(); 
        for(auto x : tree[i]) {
            if (d[x]) continue;
            d[x] = c;
            q.push({x, c});
        }
        q.pop();
    }
    int ans = 0;
    for(int i = 0; i < N; i++) {
        ans += d[i];
    }
    cout << (ans > 0 ? "Fennec" : "Snuke") << endl;
    return 0;
}