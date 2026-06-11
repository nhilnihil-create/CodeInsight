#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    int n, k;
    cin >> n >> k;

    vector<int> l(n);
    rep(i, n) {
        cin >> l.at(i);
    }

    sort(l.rbegin(), l.rend());
    int res = 0;
    for (int j = 0; j < k; ++j) {
        res += l.at(j);
    }

    cout << res << endl;
    return 0;
}
