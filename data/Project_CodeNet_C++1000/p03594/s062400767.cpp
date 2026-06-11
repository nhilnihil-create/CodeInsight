#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
#define repr(i, a, b) for(int i = a; i >= b; i--)
#define int long long
#define all(a) a.begin(), a.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef pair<int, int> P;
const int mod = 1000000007;
const int INF = 1e15;

int a[4010][4010];
char c[510][510];
string s = "RYGB";

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int h, w, d;
    cin >> h >> w >> d;
    rep(i, 0, 4010){
        rep(j, 0, 4010){
            a[i][j] = ((i / d) % 2) * 2 + ((j / d) % 2);
        }
    }
    rep(i, 0, h){
        rep(j, 0, w){
            int tmp = a[2000 + i + j][2000 + i - j];
            c[i][j] = s[tmp];
            cout << c[i][j];
        }
        cout << endl;
    }
}