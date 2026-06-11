#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using Pi = pair<int, int>;
using Pl = pair<ll, ll>;
using vint = vector<int>;
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

int cnt[100005] = {};
int pc[100005] = {}; //jouyo
int cc[100005] = {};    //jouyo
int X[100005];
int main() {
        int N, M;

        cin >> N >> M;
        for (int i = 0; i < N; i++) {
                cin >> X[i];
                cnt[X[i]]++;
                if (cnt[X[i]] % 2 == 0) pc[X[i] % M]++;
                cc[X[i] % M]++;
        }

        int ans = 0;
        for (int i = 1; i < (M + 1) / 2; i++) {
                int num = min(cc[i], cc[M - i]);
                ans += num;
                ans += min((cc[i] - num) / 2, pc[i]);
                ans += min((cc[M - i] - num) / 2, pc[M - i]);
        }
        if (M % 2 == 0) ans += cc[M / 2] / 2;
        ans += cc[0] / 2;

        cout << ans << endl;
        return (0);
}