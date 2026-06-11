#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<string> vs;
// #define INF __INT32_MAX__
#define INF 1e9
#define LINF __LONG_LONG_MAX__

int main() {
    ll N, A, B; cin >> N >> A >> B;

    if ((N == 1) && (A != B)) {
        cout << 0 << endl;
        return 0;
    }

    ll x = (N - 1) * A + B;
    ll y = (N - 1) * B + A;

    cout << max(y - x + 1, (ll) 0) << endl;
}
