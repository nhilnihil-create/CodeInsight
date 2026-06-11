#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ALL(vec) vec.begin(), vec.end()
#define rALL(vec) vec.rbegin(), vec.rend()
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    rep(i, N) cin >> a[i];
    int one = 0;
    int two = 0;
    int four = 0;
    rep(i, N) {
        if (a[i] % 4 == 0) four += 1;
        else if (a[i] % 2 == 0) two += 1;
        else one += 1;
    }
    if (two == 0) {
        if (four + 1 >= one && (1 <= four || one == 0)) cout << "Yes" << endl;
        else cout << "No" << endl;
    } else {
        if (four >= one) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}