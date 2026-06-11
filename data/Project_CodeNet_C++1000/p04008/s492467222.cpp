#include <bits/stdc++.h>

using namespace std;

#define REP(var, n)  for (decltype(n) var = 0; var < (n); var++)
#define RREP(var, n)  for (auto var = n - 1; var != static_cast<decltype(var)>(-1); var--)
#define FOR(var, a, b)  for (auto var = (a); var < (b); var++)
#define RFOR(var, a, b)  for (auto var = b - 1; var != a; var--)

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

#define all(c) begin(c),end(c)

template<typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &v) {
    if (!v.empty()) {
        out << '[';
        std::copy(v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
        out << "\b\b]";
    }
    return out;
}

const int INF = 1 << 29;

int solve() {
    int N, K;
    cin >> N >> K;
    vi a(N);
    for (auto &&e: a) {
        cin >> e;
        e--;
    }

    if (K == 1) {
        return count_if(all(a), [](int e) { return e != 0; });
    }

    vi dp(N);
    copy(all(a), begin(dp));
    if (dp[0] != 0) {
        dp[0] = 0;
    }

    vi depth(N, INF);
    vector<vi> edges(N);
    REP(i, N) {
        edges[dp[i]].push_back(i);
    }
    vector<bool> ignorance(N, false);
    ignorance[0] = true;
    function<void(int, int)> dfs = [&](int n, int d) {
        depth[n] = d;
        for (auto &&e:edges[n]) {
            if (!ignorance[e])
                dfs(e, d + 1);
        }
    };
    dfs(0, 0);

    priority_queue<pair<int, int>> que;
    REP(i, N) {
        que.push(make_pair(depth[i], i));
    }
    while(!que.empty()) {
        pair<int,int> top = que.top();
        que.pop();

        int d = top.first;
        int n = top.second;

        if(d <= K) break;
        if(d > depth[n]) {
            que.push(make_pair(depth[n], n));
            continue;
        }

        REP(i, K-1) {
            n = dp[n];
        }

        dp[n] = 0;
        dfs(n, 1);
        ignorance[n] = true;
    }

    int res = 0;
    REP(i,N) {
        if(a[i] != dp[i])res++;
    }
    return res;
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cout << solve() << endl;
//    solve();
    return 0;
}
