#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using Pi = pair<int, int>;
using Pl = pair<ll, ll>;
using vint = vector<int>;
using vll = vector<ll>;
template<typename T> using uset = unordered_set<T>;
template<typename T1, typename T2> using umap = unordered_map<T1, T2>;

constexpr int INF = (1 << 30) - 1;
constexpr ll LLINF = 1LL << 60;
constexpr int dy[] = {1, 0, -1, 0, 1, -1, -1, 1};
constexpr int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
constexpr char el = '\n';
constexpr int mod = 1000000007;

template<typename T> T gcd(T a, T b) { return (b ? gcd(b, a % b) : a); }
template<typename T> T lcm(T a, T b) { return (a / gcd(a, b) * b); }
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b) { if (a < b) a = b; }

ll N;
ll A[100005];
vector<vll> G(100005);
bool ok = true;

ll dfs(ll v, ll prev) {
        if (G[v].size() == 1) return (A[v]);
        ll sum = 0ll;
        int cnt = 0;
        ll maxv = 0;
        for (auto &u : G[v]) {
                if (u != prev) {
                        ll val = dfs(u, v);
                        if (val > 0) {
                                cnt++;
                                sum += val;
                                maxv = max(maxv, val);
                        }
                }
        }

        if (cnt == 0) return (A[v]);
        if (cnt == 1) {
                if (sum != A[v]) ok = false;
                return (A[v]);
        }
        
        if (sum < A[v]) ok = false;
        if (sum > A[v] * 2 || maxv > A[v]) ok = false;
        return (A[v] * 2 - sum);
}

int main() {
        cin >> N;
        for (int i = 0; i < N; i++) {
                cin >> A[i];
        }
        for (int i = 0; i < N - 1; i++) {
                int a, b;
                cin >> a >> b; --a, --b;
                G[a].push_back(b);
                G[b].push_back(a);
        }
        if (N == 2) {
                if (A[0] == A[1]) cout << "YES" << endl;
                else cout << "NO" << endl;
                return (0);
        }
        for (int i = 0; i < N; i++) {
                if (G[i].size() > 1) {
                        ll a = dfs(i, -1);
                        if (ok && a == 0) cout << "YES" << endl;
                        else cout << "NO" << endl;
                        break;
                }
        }
    return (0);
}