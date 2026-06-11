#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ALL(vec) vec.begin(), vec.end()
#define rALL(vec) vec.rbegin(), vec.rend()
using namespace std;
using ll = long long;
// ------------------------------

int main() {
    int N;
    cin >> N;
    int o = 0, e = 0;
    rep(i, N) {
        int A;
        cin >> A;
        A % 2 == 0 ? e += 1 : o += 1;
    }
    cout << (o % 2 == 0 ? "YES" : "NO") << endl;
    return 0;
}