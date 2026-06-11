#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")

#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) v.begin(), v.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;

int main() {
    int N, result = 0;
    cin >> N;
    vector<int> l(N), r(N);
    REP(i, N) {
        cin >> l[i] >> r[i];
    }
    REP(i, N) {
        result += r[i] - l[i] + 1;
    }
    cout << result << endl;
}
