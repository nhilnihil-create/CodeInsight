#include <bits/stdc++.h>
using namespace std;
 
#define int         long long
#define endl        "\n"
#define pii         pair<int, int>
 
 
void solve(int TC) {
    int r, c; cin >> r >> c;
    char a[r][c];
    for(int i=0; i<r; i++) for(int j=0; j<c; j++) cin >> a[i][j];
    char b[r+2][c+2];
    for(int i=0; i<r+2; i++) for(int j=0; j<c+2; j++) b[i][j] = '#';
    for(int i=1; i<=r; i++) for(int j=1; j<=c; j++) b[i][j] = a[i-1][j-1];
    for(int i=0; i<r+2; i++) {
        for(int j=0; j<c+2; j++) {
            cout << b[i][j];
        }
        cout << endl;
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