#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")

#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n+m; i++)
#define ALL(v) v.begin(), v.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;

int main() {
    int N, result = 0;
    cin >> N;
    vector<int> a(N);
    vector<bool> can(N);
    REP(i, N) {
        cin >> a[i];
        can[i] = false;
    }
    REP(i, N) {
        if (a[a[i]-1] == i+1) {
            if (can[a[i]-1] == false && can[i] == false) {
                result++;
                can[a[i]-1] = true;
                can[i] = true;
            }
        }
    }
    cout << result << endl;
    return 0;
}
