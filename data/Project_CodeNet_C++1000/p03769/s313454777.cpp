#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; ++i)
typedef long long ll;
using namespace std;
const int INF = 1e9;

int main() {
    ll N;
    cin >> N;

    deque<int> ans;
    vector<bool> div;
    int m = 1;

    while (N) {
        if (N % 2) {
            div.push_back(1);
            N /= 2;
        } else {
            div.push_back(0);
            N--;
        }
    }

    for (int i = div.size() - 1; i >= 0; --i) {
        if (div[i])
            ans.push_back(m);
        else
            ans.push_front(m);
        m++;
    }

    rep(i, m - 1) ans.push_back(i + 1);

    cout << ans.size() << endl;
    rep(i, ans.size()) {
        if (i != 0)
            cout << " ";
        cout << ans[i];
    }
    cout << endl;

    return 0;
}