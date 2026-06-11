#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = (int)(n - 1); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
#define get_unique(x) x.erase(unique(all(x)), x.end());
typedef long long ll;
typedef complex<double> Complex;
const int INF = 1e9;
const ll MOD = 1e9 + 7;
const ll LINF = 1e18;
template <class T>
bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T& a, const T& b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
vector<T> make_vec(size_t a) {
    return vector<T>(a);
}
template <class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}
template <typename T>
ostream& operator<<(ostream& os, vector<T> v) {
    for (int i = 0; i < sz(v); i++) {
        os << v[i];
        if (i < sz(v) - 1) os << " ";
    }
    return os;
}
int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> x(n);
    vector<int> xx(n);
    rep(i, n) {
        cin >> x[i].first, x[i].first--;
        x[i].second = i + 1;
        xx[i] = x[i].first;
    }
    vector<int> ans(n * n, -1);
    sort(all(x));
    queue<int> q, qq;
    for (auto p : x) {
        int idx, num;
        tie(idx, num) = p;
        ans[idx] = num;
        rep(_, num - 1) q.push(num);
        rep(_, n - num) qq.push(num);
    }

    rep(i, n * n) {
        if (ans[i] != -1) {
            if (q.front() == ans[i]) {
                cout << "No" << endl;
                return 0;
            }
        } else if (sz(q)) {
            ans[i] = q.front();
            q.pop();
        }
    }
    rep(i, n * n) {
        if (ans[i] == -1) {
            ans[i] = qq.front();
            qq.pop();
        }
    }

    vector<int> cnt(n), xxx(n, INF);
    rep(i, n * n) {
        cnt[ans[i] - 1]++;
        rep(j, n) {
            if (cnt[j] == j + 1) {
                chmin(xxx[j], i);
            }
        }
    }
    rep(i, n) {
        if (xx[i] != xxx[i]) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    cout << ans << endl;
}