#include <bits/stdc++.h>
#define ALL(obj) begin(obj), end(obj)
#define debug(x) cerr << #x << ": " << x << '\n'
using namespace std;
template <class T>
vector<T> make_vec(size_t a) {
    return vector<T>(a);
}
template <class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}
template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}

using ll = long long;
using ull = unsigned long long;
const int INF = 1e9;
// const int MOD = 1e9 + 7;

int main() {
    string s;
    cin >> s;
    set<char> se;
    for (auto c : s) {
        se.insert(c);
    }
    int ans = INF;
    for (auto c : se) {
        string now = s;
        int cnt = 0;
        while (true) {
            bool flag = true;
            for (int i = 0; i < (int)now.size() - 1; i++) {
                if (now[i] != now[i + 1]) flag = false;
            }
            if (flag) {
                break;
            }
            string next;
            for (int i = 0; i < (int)now.size() - 1; i++) {
                if (now[i] == c || now[i + 1] == c) {
                    next.push_back(c);
                } else {
                    next.push_back(now[i]);
                }
            }
            cnt++;
            now = next;
        }
        chmin(ans, cnt);
    }
    cout << ans << endl;
}
