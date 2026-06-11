#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PI 3.141592653589793
#define rep(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, n) for (int i = a; i < (n); i++)
#define rrep(i, n, k) for (int i = (n); i >= (k); i--);
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
template<class T> istream &operator>>(istream&is,vector<T>&v){for(auto &elemnt:v)is>>elemnt;return is;}
template<class T,class U> istream &operator>>(istream&is,pair<T,U>&p){is>>p.first>>p.second;return is;}
template<class T>vector<T> make_vector(size_t a){return vector<T>(a);}
template<class T, class... Ts>auto make_vector(size_t a, Ts... ts){return vector<decltype(make_vector<T>(ts...))>(a, make_vector<T>(ts...));}
const int MOD = 1e9+ 7;
const int INF = 2e18;

struct info {
    int v, d, c;
};

signed main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N + 1);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int Q;
    cin >> Q;
    vector<info> input(Q);
    for (int i = 0; i < Q; i++) {
        int v, d, c;
        cin >> v >> d >> c;
        input[i] = {v, d, c};
    }
    set<pair<int, int>> check;
    vector<int> ans(N + 1, 0);
    function<void(info)> explore = [&](info now) {
        if (check.find({now.v, now.d}) != check.end()) return;
        check.emplace(now.v, now.d);
        if (ans[now.v] == 0) ans[now.v] = now.c;
        if (now.d == 0) return;
        explore({now.v, now.d - 1, now.c});
        for (auto next : G[now.v]) explore({next, now.d - 1, now.c});
    };
    reverse(input.begin(), input.end());
    for (auto temp : input) explore(temp);
    for (int i = 1; i <= N; i++) {
        cout << ans[i] << endl;
    }
}
