#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#include <cassert>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
using namespace std;
using ll = long long;
constexpr ll INF = 3000000000000000000;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    REP(i, n) cin >> a[i];
    
    int mx = 0, mn = n;
    REP(i, n) {
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
    }
    if (mx - mn > 1) {
        cout << "No\n";
    } else if (mx - mn == 1) {
        int cnt = 0;
        REP(i, n) {
            if (a[i] == mx) ++cnt;
        }
        if (cnt == 1) {
            cout << "No\n";
        } else {
            int d = n - cnt + 1;
            int u = n - cnt + cnt / 2;
            if (mx >= d && mx <= u) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
    } else {
        int d = 1;
        int u = n / 2;
        if (mx >= d && mx <= u) {
            cout << "Yes\n";
        } else {
            if (mx == n - 1) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
    }
    
    return 0;
}
