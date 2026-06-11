#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
#define INF __INT32_MAX__
#define LINF __LONG_LONG_MAX__

int main() {
    ll N, K;
    cin >> N >> K;

    vector<pair<int, int>> A(N);
    rep(i, N) {
        int x, y;
        cin >> x >> y;
        A[i] = make_pair(x, y);
    }

    sort(A.begin(), A.end(), [](const auto &a, const auto &b) {
        return a.first < b.first;
    });

    ll bsum = 0;
    rep(i, N) {
        int a = A[i].first;
        int b = A[i].second;

        bsum += b;
        if (bsum >= K) {
            cout << a << endl;
            break;
        }
    }
}