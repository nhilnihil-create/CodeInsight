#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<string> vs;
// #define INF __INT32_MAX__
#define INF 1e9
#define LINF __LONG_LONG_MAX__

int main() {
    int N; cin >> N;
    vl A(N);
    rep(i, N) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    vl sum(N);
    rep(i, N) {
        sum[i] = A[i];
    }
    rep(i, N - 1) {
        sum[i + 1] += sum[i];
    }

    int cnt = 1;
    for (int i = N - 1; i >= 1; i--) {
        if ((2 * sum[i - 1]) >=  A[i]) {
            cnt++;
        } else {
            break;
        }
    }

    cout << cnt << endl;
}
