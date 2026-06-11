#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

// #define int ll
#define REP(i,n) for (int i = 0; i < (n); ++i)
#define FORE(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << '\n'
#define hyphen() cerr << "--\n"

#define fst first
#define pb push_back

const int MOD = (int)1e9 + 7;

signed main() {
    int N, M;
    cin >> N >> M;

    vector<int> cnt(N);
    REP(i, M) {
        int A, B;
        cin >> A >> B;
        cnt.at(A-1) += 1;
        cnt.at(B-1) += 1;
    }

    REP(i, N) {
        if (cnt.at(i) % 2 == 1) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}
