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
void print() { cout << "\n"; }
template <class T> void print(const T &x) { cout << x << "\n"; }
template <class T, class... Args> void print(const T &x, const Args &... args) {
    cout << x << " ";
    print(args...);
}
template <class T> void printVector(const vector<T> &v) {
    for(const T &x : v) {
        cout << x << " ";
    }
    cout << "\n";
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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> num[m];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        num[a[i] % m].emplace_back(a[i]);
    }
    for(int i = 0; i < m; i++) {
        sort(ALL(num[i]));
        // cerr << i << ": ";
        // for(auto j : num[i]) {
        //     cerr << j << " ";
        // }
        // cerr << endl;
    }
    int ans = 0;
    for(int i = 0; i <= (m / 2); i++) {
        int j = m - i;
        int size_i = num[i].size(), size_j = num[j].size();
        if(i == 0 || i == j) {
            ans += size_i / 2;
            continue;
        }
        auto vi = num[i];
        auto vj = num[j];
        if(size_i > size_j) {
            swap(vi, vj), swap(size_i, size_j);
        }
        map<int, int> cnt;
        for(int k : vj) {
            cnt[k]++;
        }
        int paircnt = 0;
        for(auto p : cnt) {
            paircnt += p.second / 2;
        }
        ans += size_i + min((size_j - size_i) / 2, paircnt);
    }
    print(ans);
}