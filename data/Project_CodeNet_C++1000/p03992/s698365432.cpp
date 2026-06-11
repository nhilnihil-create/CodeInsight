#include <bits/stdc++.h>
#define rep(i, a) for(int i = 0; i < a; i++)
#define all(v) v.begin(), v.end()
#define int long long
using namespace std;
signed main() {
    string s;
    cin >> s;
    rep(i, s.size()) {
        cout << s[i];
        if(i == 3) cout << " ";
    }
    cout << endl;
    return 0;
}