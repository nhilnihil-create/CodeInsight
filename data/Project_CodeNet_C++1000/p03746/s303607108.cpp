#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstring>
#include<utility>
#include<cmath>
#include<assert.h>

#define int long long
using namespace std;
#define rep(i, n) for(int i=0;i<(n);++i)
typedef pair<int, int> pii;
const int INF = 1l << 60;
#define u_b upper_bound
#define l_b lower_bound

int N, M;
vector<int> G[100100];
bool visited[100100];
deque<int> path;

int ok(int idx) {
    for (int v:G[idx]) {
        if (!visited[v])return v;
    }
    return 0;
}

signed main() {
    cin >> N >> M;
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    visited[0] = true;
    visited[G[0][0]] = true;
    path.push_front(0);
    path.push_back(G[0][0]);
    int left = 0;
    while (left = ok(left)) {
        visited[left] = true;
        path.push_front(left);
    }
    int right = G[0][0];
    while (right = ok(right)) {
        visited[right] = true;
        path.push_back(right);
    }
    cout << path.size() << endl;
    while (!path.empty()) {
        cout << path.front() + 1 << " ";
        path.pop_front();
    }
    return 0;
}
