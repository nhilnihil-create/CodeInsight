#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

bool is_valid(int m, vector<int> &d) {
    string s = to_string(m);
    rep(i, d.size()) {
        int pos = s.find(to_string(d[i]));
        if (pos != -1) return false;
    }
    return true;
}

int main() {
    int n,k; cin >> n >> k;
    vector<int> d(k);
    rep(i,k) cin >> d.at(i);

    int ans = n;
    for (;;ans++) {
        if(is_valid(ans,d)) break;
    }

    cout << ans << endl;
}