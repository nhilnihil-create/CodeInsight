#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
using namespace std;
using ll = int64_t;
using vi = vector<int>;
using vvi = vector<vi>;


int main() {
    int s[2], t[2];
    cin >> s[0] >> s[1] >> t[0] >> t[1];
    rep(i, t[1]-s[1]) {
        cout << 'U';
    }
    rep(i, t[0] - s[0]) {
        cout << 'R';
    }
    rep(i, t[1]-s[1]) {
        cout << 'D';
    }
    rep(i, t[0] - s[0]) {
        cout << 'L';
    }
    cout << 'D';
    rep(i, t[0]-s[0]+1) {
        cout << 'R';
    }
    rep(i, t[1]-s[1]+1) {
        cout << 'U';
    }
    cout << 'L';
    cout << 'U';
    rep(i, t[0]-s[0]+1) {
        cout << 'L';
    }
    rep(i, t[1]-s[1]+1) {
        cout << 'D';
    }
    cout << 'R' << '\n';
}