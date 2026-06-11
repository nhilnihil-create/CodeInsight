#include <bits/stdc++.h>
using namespace std;
typedef long long Int;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n; cin >> n;
    vector<bool> p(n);
    for (int i = 1; i < n+1; i++) {
        int tmp;
        cin >>tmp;
        if (i == tmp)
            p[i-1] = true;
        else
            p[i-1] = false;
        
    }
    int ans = 0;
    rep(i, n) {
        if (p[i] == true) {
            ans++;
            if (i != n-1)
                p[i+1] = false;
        }
    }
    cout << ans << endl;
}