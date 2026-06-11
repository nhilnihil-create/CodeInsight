#include <bits/stdc++.h>
using namespace std;
 
#define int         long long
#define endl        "\n"
#define pii         pair<int, int>
 
 
void solve(int TC) {
    int a, b; cin >> a >> b;
    int c = a + b;
    if(c >= 10) {
        cout << "error";
    } else {
        cout << c;
    }
}
 
signed main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(12);
 
 
    int T = 1;
    //cin >> T;
    for(int i=1; i<=T; i++) {
        solve(i);
    }
    return 0;
 
}