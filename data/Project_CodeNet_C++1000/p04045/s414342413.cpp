#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
#define INF __INT32_MAX__
#define LINF __LONG_LONG_MAX__

bool check(vi list, int val) {
    bool ok = true;

    while (val > 0) {
        int digit = val % 10;
        bool tmpng = false;
        rep(i, list.size()) {
            if (digit == list[i]) {
                tmpng = true;
                ok = false;
                break;
            }
        }
        if (tmpng) break;

        val /= 10;
    }

    return ok;
}

int main() {
    int N, K;
    cin >> N >> K;
    vi D(K);
    rep(i, K) {
        cin >> D[i];
    }

    while (1) {
        if (check(D, N)) {
            break;
        }
        N++;
    }

    cout << N << endl;
}