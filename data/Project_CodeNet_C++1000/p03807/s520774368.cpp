#include <bits/stdc++.h>

#define REP(i,n) for (int i=0;i<(n);++i)

using namespace std;

bool solve() {

    int N;
    cin >> N;
    int n_odds = 0;
    REP(i, N) {
        int A;
        cin >> A;
        if (A % 2) ++n_odds;
    }
    return n_odds % 2 == 0;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << (solve() ? "YES" : "NO") << endl;
    return 0;
}
