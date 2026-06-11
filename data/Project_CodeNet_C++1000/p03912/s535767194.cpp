#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define FOR(i, m, n) for (int i = (m); i < (n); i++)
#define REP(i, n) FOR(i, 0, n)
#define ALL(c) (c).begin(), (c).end()
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return false;}
const int MOD = 1000000007;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> x(m, vector<int>());
    int y;
    REP(i, n) {
        cin >> y; 
        x[y % m].push_back(y);
    }

    int c = 0;
    // mod m == 0
    c += x[0].size() / 2;
    // mod m == just m/2
    if (m % 2 == 0) {
        c += x[m / 2].size() / 2;
    }

    FOR(i, 1, m / 2 + 1) {
        if (m % 2 == 0 && i == m / 2) {
            continue;
        }
        if (x[i].size() == x[m - i].size()) {
            c += x[i].size();
            continue;
        }
        vector<int> large;
        vector<int> small;
        if (x[i].size() < x[m - i].size()) {
            large = x[m - i];
            small = x[i];
        } else {
            small = x[m - i];
            large = x[i];
        }
        c += small.size();
        sort(ALL(large));
        int d = 0;
        int l = (large.size() - small.size()) / 2;
        int prev = -1;
        for (const int z : large) {
            if (prev == z) {
                d++;
                prev = -1;
            } else {
                prev = z;
            }
            if (l == d) {
                break;
            }
        }
        c += d;
    }

    cout << c << endl;
}
