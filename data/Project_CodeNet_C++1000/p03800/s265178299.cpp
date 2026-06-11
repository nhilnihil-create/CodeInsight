#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; ++i)
#define REPR(i, n) for (int i = n - 1; i >= 0; --i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define FORR(i, a, b) for (int i = b - 1; i >= a; --i)
#define SORT(v) sort(v.begin(), v.end())
#define SORTR(v) sort(v.rbegin(), v.rend())
#define REV(v) reverse(v.begin(), v.end())
#define ITER(itr, v) for (auto itr = v.begin(); itr != v.end(); ++itr)
#define LB(v, x) (lower_bound(v.begin(), v.end(), x) - v.begin())
#define UB(v, x) (upper_bound(v.begin(), v.end(), x) - v.begin())
#define SZ(v) (int)v.size()
using namespace std;
using ll = long long;
using P = pair<int, int>;

class Main {
    int N;
    string s;
    void input() { cin >> N >> s; }
    void output() {
        string sw = "SW";
        REP(bit, 1 << 2) {
            vector<int> v;
            REP(i, 2) { v.emplace_back(bit >> i & 1); }
            FOR(i, 1, N) {
                if (v[i] == 0) {
                    if (s[i] == 'o') {
                        v.emplace_back(v[i - 1]);
                    } else {
                        v.emplace_back(!v[i - 1]);
                    }
                } else {
                    if (s[i] == 'o') {
                        v.emplace_back(!v[i - 1]);
                    } else {
                        v.emplace_back(v[i - 1]);
                    }
                }
            }
            if (v.front() == v.back()) {
                if (v[0] == 0) {
                    if (s[0] == 'o') {
                        if (v[N - 1] != v[1]) continue;
                    } else {
                        if (v[N - 1] == v[1]) continue;
                    }
                } else {
                    if (s[0] == 'o') {
                        if (v[N - 1] == v[1]) continue;
                    } else {
                        if (v[N - 1] != v[1]) continue;
                    }
                }
                REP(i, N) { cout << sw[v[i]]; }
                cout << endl;
                return;
            }
        }
        cout << -1 << endl;
    }

public:
    Main() {
        input();
        output();
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    Main();

    return 0;
}
