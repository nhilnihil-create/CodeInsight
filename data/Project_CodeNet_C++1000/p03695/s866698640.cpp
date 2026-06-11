#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

constexpr ll INF = ll(1e+18) + 1;

int main() {
    int N;
    int a[8] = {};
    int rate;
    int ans_min=0, ans_max=0;
    int over = 0;

    cin >> N;
    rep(i, N) {
        cin >> rate;
        if (rate < 3200) { a[rate/400]++; }
        else {over++;}
    }

    rep(i, 8) {
        if (a[i] > 0) {
            ans_min++;
        }
    }

    ans_max = ans_min+over;
    ans_min = max(ans_min, 1);

    cout << ans_min << " " << ans_max << endl;
}
