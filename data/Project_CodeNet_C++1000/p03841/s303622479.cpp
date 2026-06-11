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
        int N; cin >> N;
        vector<Pi> X(N + 1);
        vint ans(N * N + 1, -1);

        for (int i = 1; i <= N; i++) {
                cin >> X[i].first;
                X[i].second = i;
                ans[X[i].first] = i;
        }

        sort(begin(X) + 1, end(X));

        int cnt = 1;
        for (int i = 1; i <= N; i++) {
                int num = X[i].second - 1;
                int c = 0;
                if (num == 0) continue;
                while (cnt <= N * N) {
                        if (cnt == X[i].first) {
                                cout << "No" << endl;
                                return (0);
                        }
                        if (ans[cnt] == -1) {
                                ans[cnt] = X[i].second;
                                c++;
                                if (c == num) break;
                        }
                        cnt++;
                }
        }

        for (int i = 1; i <= N; i++) {
                int num = N - X[i].second;
                int c = 0;
                if (num == 0) continue;
                while (cnt <= N * N && ans[cnt] != -1) cnt++;
                if (cnt < X[i].first) {
                        cout << "No" << endl;
                        return (0);
                }
                while (cnt <= N * N) {
                        if (ans[cnt] == -1) {
                                ans[cnt] = X[i].second;
                                c++;
                                if (c == num) break;
                        }
                        cnt++;
                }
        }

        cout << "Yes" << endl;
        cout << ans[1];
        for (int i = 2; i <= N * N; i++) cout << " " << ans[i];
        cout << endl;
        return (0);
}