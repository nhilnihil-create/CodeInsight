#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
constexpr int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
constexpr int dy[] = {0, -1, 0, 1, 1, -1, -1, 1};

template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec){os << "["; for (const auto &v : vec) {os << v << ","; } os << "]"; return os; }
template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) {os << "(" << p.first << ", " << p.second << ")"; return os;}


void dfs(int v, set<int> &visit, deque<int> &visit2, vector<vector<int>> &G, bool flag) {

    for(int i = 0; i < G[v].size(); i++) {
        if (visit.find(G[v][i]) == visit.end()) {
            visit.insert(G[v][i]);
            
            if (!flag) visit2.push_front(G[v][i]);
            else visit2.push_back(G[v][i]);
            
            dfs(G[v][i], visit, visit2, G, flag);
            return; // 枝分かれしない
        }
    }
    return;
}

void solve() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    set<int> visit;
    deque<int> visit2;
    visit.insert(0);
    visit.insert(G[0][0]);
    visit2.push_back(0);
    visit2.push_back(G[0][0]);

    dfs(G[0][0], visit, visit2, G, true);
    dfs(0, visit, visit2, G, false);

    cout << visit2.size() << endl;
    for (int i = 0; i < visit2.size(); i++) {
        cout << visit2[i] + 1 << " ";
    }
    cout << endl;
}

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(16);
    solve();
    return 0;
}