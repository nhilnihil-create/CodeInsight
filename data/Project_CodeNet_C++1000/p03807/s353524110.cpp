#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<map>
#include<set>
#include<iomanip>

using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int INF = numeric_limits<int>::max();
const ll LLINF = numeric_limits<ll>::max();
const double PI = acos(-1.0);

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, a, n) for (int i = a; i <= (n); ++i)

int main() {
    int N; cin >> N;
    vector<int> A(N); rep(i, N) cin >> A[i];

    int odd_cnt = 0;
    rep(i, N) {
        if (A[i] & 1) odd_cnt++;
    }

    if (odd_cnt & 1) cout << "NO" << endl;
    else cout << "YES" << endl;
    return 0;
}
