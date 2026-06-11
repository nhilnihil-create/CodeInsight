#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int K, T;
    cin >> K >> T;
    vector<P> a(T);
    rep(i, T) {
        int tmp;
        cin >> tmp;
        a[i] = make_pair(tmp, i);
    }

    if (T == 1) {
        cout << K - 1 << endl;
        return 0;
    }

    int ans = 0;
    int pre_a = -1;
    rep(i, K) {
        sort(a.begin(), a.end(), greater<>());

        if (a[0].second != pre_a) {
            --a[0].first;
            pre_a = a[0].second;
        } else {
            if (a[1].first == 0) {
                ans = a[0].first;
                break;
            } else {
                --a[1].first;
                pre_a = a[1].second;
            }
        }
    }

    cout << ans << endl;
}