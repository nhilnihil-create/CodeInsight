#define D(x) cout << #x " = " << x << endl
#define DD(x, y) cout << "(" #x ", " #y ") = (" << x << ", " << y << ")" << endl
#define DDD(x, y, z) cout << "(" #x ", " #y ", " #z ") = (" << x << ", " << y << ", " << z << ")" << endl
#define DV(v) for (auto __macro_vi : v){ cout << __macro_vi << " ";} cout << endl;
#define DA(a, n) for (int __macro_i = 0; __macro_i < n; ++__macro_i) { cout << a[__macro_i] << " "; } cout << endl;
#define REP(i, n) for (int i = 0; i < n; ++i)
#define ALL(v) (v).begin(), (v).end()
#include<iostream>
#include<vector>
#include<cassert>
#include<cmath>
#include<map>

using namespace std;
using P = pair<int, int>;
vector<vector<P>> v;

int n, m;
int main()
{
    cin >> n >> m;
    v.resize(m);
    vector<int> tmp(n);
    REP(i, n) {
        cin >> tmp[i];
    }
    sort(tmp.begin(), tmp.end());
    for (auto ai : tmp) {
        int md = ai % m;
        if (v[md].size() != 0 && (*v[md].rbegin()).second == ai && (*v[md].rbegin()).first < 2) {
            (*v[md].rbegin()).first++;
        } else {
            v[md].push_back(make_pair(1, ai));
        }
    }
    int ans = 0;
    for (int md = 0; md <= m / 2; ++md) {
        if (md == 0 || md * 2 == m) {
            // D(md);
            int sm = 0; for (auto vi : v[md]) sm += vi.first;
            ans += sm / 2;
        } else {
            int r = m - md;
            sort(v[md].begin(), v[md].end());
            sort(v[r].begin(), v[r].end());
    
            int i = 0, j = 0;
            while (i < v[md].size() && j < v[r].size()) {
                ans += 1;
                v[md][i].first--;
                if (v[md][i].first == 0) i++;
                v[r][j].first--;
                if (v[r][j].first == 0) j++;
            }

            for (auto vi : v[md]) if (vi.first == 2) ans++;
            for (auto vi : v[r]) if (vi.first == 2) ans++;
        }
    }
    cout << ans << endl;
}
