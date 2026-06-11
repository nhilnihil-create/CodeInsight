#include <bits/stdc++.h>
using namespace std;
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
void debug() { cerr << "\n"; }
template <class T> void debug(const T &x) { cerr << x << "\n"; }
template <class T, class... Args> void debug(const T &x, const Args &... args) {
    cerr << x << " ";
    debug(args...);
}
template <class T> void debugVector(const vector<T> &v) {
    for(const T &x : v) {
        cerr << x << " ";
    }
    cerr << "\n";
}
using ll = long long;

#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
const double EPS = 1e-7;
const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
const double PI = acos(-1);
constexpr int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//-------------------------------------

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, Ma, Mb;
    cin >> N >> Ma >> Mb;
    vector<int> a(N), b(N), c(N);
    for(int i = 0; i < N; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    map<int, int> C[2];
    // 前半
    for(int bit = 1; bit < (1 << (N / 2)); bit++) {
        int sum = 0, cost = 0;
        for(int i = 0; i < (N / 2); i++) {
            if(bit & (1 << i)) {
                sum += Mb * a[i] - Ma * b[i];
                cost += c[i];
            }
        }
        if(!C[0].count(sum)) {
            C[0][sum] = cost;
        } else {
            chmin(C[0][sum], cost);
        }
    }
    // 後半
    for(int bit = 1; bit < (1 << (N - N / 2)); bit++) {
        int sum = 0, cost = 0;
        for(int i = 0; i < (N - N / 2); i++) {
            if(bit & (1 << i)) {
                int j = i + N / 2;
                sum += Mb * a[j] - Ma * b[j];
                cost += c[j];
            }
        }
        if(!C[1].count(sum)) {
            C[1][sum] = cost;
        } else {
            chmin(C[1][sum], cost);
        }
    }
    int ans = INF;
    for(int i = 0; i < 2; i++) {
        if(C[i].count(0)) {
            chmin(ans, C[i][0]);
        }
    }
    for(const auto &p : C[0]) {
        if(C[1].count(-p.first)) {
            chmin(ans, p.second + C[1][-p.first]);
        }
    }
    cout << (ans == INF ? -1 : ans) << endl;
}