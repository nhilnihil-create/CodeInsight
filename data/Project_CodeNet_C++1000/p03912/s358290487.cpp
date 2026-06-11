#include <bits/stdc++.h>
using namespace std;
#define Int int64_t
#define dump(x) cout << (x) << endl
#define fi first
#define se second
Int mod = 1e9+7;
Int INF = 1e18;
double EPS = 0.00000001;
//Int mod = 1e6+3;

int main() {
    Int n, m;
    cin >> n >> m;
    vector<map<Int, Int>> v(m);
    for (Int i = 0; i < n; i++) {
        Int x;
        cin >> x;
        v[x % m][x]++;
    }
    vector<Int> vsum(m, 0);
    vector<vector<Int>> vsum2(m);
    for (Int i = 0; i < m; i++) {
        for (auto j : v[i]) {
            vsum[i] += j.se;
            vsum2[i].emplace_back(j.se);
        }
        sort(vsum2[i].begin(), vsum2[i].end());
    }
    Int res = vsum[0] / 2;
    for (Int i = 1; i <= m - i; i++) {        
        if (i == m - i) {
            res += vsum[i] / 2;
        }
        else {
            Int add = min(vsum[i], vsum[m - i]);
            res += add;
            if (vsum[i] == vsum[m - i]) continue;
            if (vsum[i] != add) {                
                Int sum = 0;
                Int odd = 0;
                for (Int j = 0; j < (Int)vsum2[i].size(); j++) {
                    if (vsum2[i][j] % 2 == 1 && odd < add) {
                        odd++;
                        vsum2[i][j]--;
                    }       
                    sum += vsum2[i][j];             
                }
                if (odd < add) {
                    res += (sum - (add - odd)) / 2;
                }
                else {
                    for (Int j = 0; j < (Int)vsum2[i].size(); j++) {
                        res += vsum2[i][j] / 2;
                    }
                }
            }
            else {
                Int sum = 0;
                Int odd = 0;
                for (Int j = 0; j < (Int)vsum2[m - i].size(); j++) {
                    if (vsum2[m - i][j] % 2 == 1 && odd < add) {
                        odd++;
                        vsum2[m - i][j]--;
                    }
                    sum += vsum2[m - i][j];
                }
                if (odd < add) {
                    res += (sum - (add - odd)) / 2;
                }
                else {
                    for (Int j = 0; j < (Int)vsum2[m - i].size(); j++) {
                        res += vsum2[m - i][j] / 2;
                    }
                }
            }
        }
    }
    dump(res);
    return 0;
}
