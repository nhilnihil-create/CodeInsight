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
    string s, t;
    cin >> s >> t;
    
    vector<int> s_sum(SZ(s) + 1, 0), t_sum(SZ(t) + 1, 0);
    REP(i, SZ(s)) {
        if (s[i] == 'A') s_sum[i + 1] = s_sum[i] + 1;
        else s_sum[i + 1] = s_sum[i];
    }
    REP(i, SZ(t)) {
        if (t[i] == 'A') t_sum[i + 1] = t_sum[i] + 1;
        else t_sum[i + 1] = t_sum[i];
    }
    
    int q;
    cin >> q;
    REP(_, q) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        --a; --c;
        int s_a = s_sum[b] - s_sum[a];
        int s_b = b - a - s_a;
        int t_a = t_sum[d] - t_sum[c];
        int t_b = d - c - t_a;
        if (((s_a + s_b * 2) - (t_a + t_b * 2)) % 3) cout << "NO\n";
        else cout << "YES\n";
    }
    
    return 0;
}
