/*
ID: y1197771
PROG: test
LANG: C++
*/
#include<bits/stdc++.h>
#define pb push_back
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
#define dbg(x) cout << #x << " at line " << __LINE__ << " is: " << x << endl
typedef long long ll;
using namespace std;
typedef pair<int, int> pii;
const int maxn = 1e3 + 10;
int h, w;
string a[30][30];
void solve() {
    cin >> h >> w;
    string tar = "snuke";
    int x, y;
    x = y = 0;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) {
            cin >> a[i][j];
            if(a[i][j] == tar) {
                x = i, y = j;
            }
        }
    cout << char('A' + y) << x + 1 << endl;

}
int main() {
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
