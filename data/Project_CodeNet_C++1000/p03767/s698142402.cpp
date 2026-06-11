#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    int N;
    cin >> N;

    vector<int> a(3 * N);
    rep (i, 3 * N) {
        cin >> a.at(i);
    }

    sort(a.begin(), a.end());

    ll res = 0;

    for (int i = N; i < 3 * N ; i += 2) {
        res += a.at(i);
    }
    cout << res << endl;


}
