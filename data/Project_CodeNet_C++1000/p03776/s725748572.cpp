#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

constexpr ll infl = 10000000000000007LL;
constexpr int inf = 1000000007;

int main() {
    vector<vector<ll>> comb(50 + 1, vector<ll>(50 + 1));
    comb[0][0] = 1;
    for (int i = 0; i <= 49; ++i) {
        for (int j = 0; j <= i; ++j) {
            comb[i + 1][j] += comb[i][j];
            comb[i + 1][j + 1] += comb[i][j];
        }
    }
    int n, a, b;
    cin >> n >> a >> b;
    vector<ll> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.rbegin(), v.rend());
    if (v[0] != v[a - 1]) {
        double average = 0;
        int cnt_1 = 0;
        for (int i = 0; i < a; ++i) {
            average += v[i];
            cnt_1 += v[i] == v[a - 1];
        }
        average /= a;
        ll cnt_2 = 0;
        for (int i = a; i < n; ++i) {
            cnt_2 += v[i] == v[a - 1];
        }
        cout << fixed << setprecision(10) << average << endl;
        cout << comb[cnt_1 + cnt_2][cnt_1] << endl;
    } else {
        int cnt_same = 1;
        for (int i = 1; i < n; ++i) {
            cnt_same += v[i] == v[0];
        }
        ll cnt = 0;
        for (int i = a; i <= min(b, cnt_same); ++i) {
            cnt += comb[cnt_same][i];
        }
        cout << fixed << setprecision(10) << v[0] << endl;
        cout << cnt << endl;
    }
    return 0;
}