#include <bits/stdc++.h>
 
#define rep(...) overload_rep(__VA_ARGS__, rep_1, rep_0)(__VA_ARGS__)
#define rep_0(i, end) for(int i = 0; i < (end); ++i)
#define rep_1(i, fr, ba) for(int i = (fr); i <= (ba); ++i)
#define overload_rep(arg0, arg1, arg2, name, ...) name
#define all(box) box.begin(), box.end()
 
template <class T, class U> inline bool chmax(T& lhs, const U& rhs) { if (lhs < rhs) { lhs = rhs; return 1; } return 0; }
template <class T, class U> inline bool chmin(T& lhs, const U& rhs) { if (lhs > rhs) { lhs = rhs; return 1; } return 0; }

using lint = long long;

int main() {

    int N;
    std::cin >> N;
    std::vector<lint> A(N);
    std::vector<std::vector<int>> graph(N);
    rep (i, N) std::cin >> A[i];
    rep (i, N - 1) {
        int a, b;
        std::cin >> a >> b;
        --a; --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    if (N == 2) {
        std::cout << (A[0] == A[1] ? "YES" : "NO") << '\n';
        return 0;
    }

    bool answer = true;
    std::function<lint(int, int)> dfs = [&] (const int& v, const int& prev) {
        if (graph[v].size() == 1) return A[v];
        lint max = 0, sum = 0;
        for (const int& u : graph[v]) {
            if (u == prev) continue;
            lint tmp = dfs(u, v);
            chmax(max, tmp);
            sum += tmp;
        }
        chmax(max, (sum + 1) / 2);
        if (A[v] < max || A[v] > sum) {
            answer = false;
        }
        return sum - (sum - A[v]) * 2;
    };

    rep (i, N) {
        if (graph[i].size() > 1) {
            if (dfs(i, -1) != 0) answer = false;
            break;
        }
    }
    std::cout << (answer ? "YES" : "NO") << '\n';
    return 0;

}
