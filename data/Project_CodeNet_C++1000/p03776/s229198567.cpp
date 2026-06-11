#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <iomanip>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    int N, A, B;
    cin >> N >> A >> B;
    vector<long long> v(N);
    rep(i, N) cin >> v[i];
    
    map<long long, int> cnt;
    rep(i, N) ++cnt[v[i]];
    
    long long now = 0;
    int c = 0;
    map<long long, int> use;
    sort(v.rbegin(), v.rend());
    rep(i, B) {
        if (i < A) {
            now += v[i];
            ++use[v[i]];
            ++c;
        } else {
            if (v[i] == v[0]) {
                now += v[i];
                ++use[v[i]];
                ++c;
            }
        }
    }
    
    cout << fixed << setprecision(10) << now / (double)c << endl;
    
    vector<vector<long long>> comb(60, vector<long long>(60));
    rep(i, 60) rep(j, 60) {
        if (j > i) {
            continue;
        } else if (j == 0 || j == i) {
            comb[i][j] = 1;
        } else {
            comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
        }
    }
    if (use.size() == 1) {
        long long ans = 0;
        for (int i = A; i <= B; ++i) {
            ans += comb[cnt[v[0]]][i];
        }
        cout << ans << endl;
        return 0;
    }
    long long ans = 1;
    for (auto n : use) {
        ans *= comb[cnt[n.first]][use[n.first]];
    }
    cout << ans << endl;
    return 0;
}
