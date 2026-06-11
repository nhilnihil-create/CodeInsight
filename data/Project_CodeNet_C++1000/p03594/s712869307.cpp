#include <bits/stdc++.h>
using namespace std;
int d;
int f[501][501];
void solve(int x, int y) {
    int q = x;
    if ( ( x + y) % 2 != 0) x++;
    int a = (x + y) / 2; int b = ( x - y) / 2; int t = d / 2;
    a = a % d; b = ((b % d) + d) % d;
    if ( a < t && b < t) cout << "R";
    else if ( a < t && b >= t) cout << "Y";
    else if ( a >= t && b < t) cout << "G";
    else cout << "B";

}
int main() {
    ios_base::sync_with_stdio(false);
    int h, w;
    cin >> h >> w;
    cin >> d;
    if ( d % 2 != 0) {
        for ( int i = 1; i <= h; i++) {
            for ( int j = 1; j <= w; j++) {
                if ( ( i + j) % 2 == 0) cout << "R";
                else cout << "Y";
            }
            cout << '\n';
        }
        return 0;
    }
    for (int i = 1; i <= h; i++) {
        for ( int j = 1; j <= w; j++) {
            solve(i, j);
        }
        cout << '\n';
    }
    return 0;
}
