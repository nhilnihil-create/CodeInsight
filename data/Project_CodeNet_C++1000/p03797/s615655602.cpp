#include <bits/stdc++.h>
using namespace std;
typedef long long Int;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    Int n, m; cin >> n >> m;
   
   Int ans = 0;
    if (n == m/2) cout << n <<  endl;
    else if (n > m/2) {
        cout << m/2 << endl;
    }
    else {
        Int ans = n;
        m = m - n -n;
        cout << ans + (m/4) << endl;
    }
}