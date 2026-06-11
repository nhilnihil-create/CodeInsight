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

int main() {
        ll N, M;
        cin >> N >> M;
        int sum[100006] = {};   

        for (int i = 0; i < N; i++) {
                int l, r;
                cin >> l >> r;
                int minv = M + 1;
                for (int j = 1; j < minv && j * j <= r; j++) {
                        int a = l / j * j, b = r / j * j;
                        if (l <= a && a <= r || l <= b && b <= r) sum[j]++, sum[j + 1]--;
                        int dl = l / j, dr = r / j;
                        if (dl * j < l) dl++;
                        dl = max(dl, j + 1);
                        dr = min(dr, minv - 1);
                        if (dl > dr) continue;
                        sum[dl]++, sum[dr + 1]--;
                        minv = min(minv, dl);
                }
        }
        int d = 0;      
        for (int i = 1; i <= M; i++) {
                d += sum[i];
                cout << d << el;
        }
    return (0);
}