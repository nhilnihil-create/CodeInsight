#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pii pair<int, int>
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep3(i, l, n) for (int i = l; i < n; ++i)
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define chmax(a, b) a = (a >= b ? a : b)
#define chmin(a, b) a = (a <= b ? a : b)
#define out(a) cout << a << endl
#define outa(a, n) { rep(_, n) cout << a[_] << " "; cout << endl; }
#define outp(a, n) { cout << endl; rep(_, n) cout << a[_].F << " " << a[_].S << endl; }
#define SZ(v) (int)v.size()
#define inf (int)(1e9+7)
#define abs(x) (x >= 0 ? x : -(x))
#define ceil(a, b) a / b + !!(a % b)
#define FIX(a) fixed << setprecision(a)
#define LB(v, n) (int)(lower_bound(all(v), n) - v.begin())
#define UB(v, n) (int)(upper_bound(all(v), n) - v.begin())

int main() {
    int n, x;
    cin >> n >> x;
    
    if (x == 1 || x == 2 * n - 1) {
        out("No");
        return 0;
    }
    
    out("Yes");
    
    if (n == x || n == 2) {
        rep(i, 2 * n - 1) out(i + 1);
        return 0;
    }
    
    // とりあえず小さいケース
    if (n == 3) {
        if (x == 2) {
            out("5 1 2 3 4");
        } else if (x == 4) {
            out("1 5 4 3 2"); // x == 2と対照的
        }
        return 0;
    }
    
    if (n == 4) {
        if (x == 6) {
            out("2 5 1 6 7 3 4");
        } else if (x == 2) {
            out("6 3 7 2 1 5 4"); // x == 6と対照的
        } else if (x == 5) {
            out("4 1 5 3 7 6 2");
        } else if (x == 3) {
            out("4 7 3 5 1 2 6");
        }
    }
    
    // 端以外できそうやけど...
    // わからん!!
    
    // 解説ac pdf
    /*
          x  x
          x  x
     x+2 x-1 x x+1
     ただし、x+2が存在しないといけない
     他の考える(逆に小さい方)
     
         x  x
     x-1 x x+1 x-2
     x-2が存在しないといけない
     */
    
    if (x != 2) {
        vector<int> v;
        int cnt = 0;
        rep3(i, 1, 2 * n + 1) {
            if (i != x - 1 && i != x && i != x + 1 && i != x - 2) {
                v.eb(i);
                cnt++;
                if (cnt == n - 2) {
                    v.eb(x - 1);
                    v.eb(x);
                    v.eb(x + 1);
                    v.eb(x - 2);
                }
            }
        }
        outa(v, 2 * n - 1);
    } else {
        vector<int> v;
        int cnt = 0;
        rep3(i, 1, 2 * n + 1) {
            if (i != x + 2 && i != x - 1 && i != x && i != x + 1) {
                v.eb(i);
                cnt++;
                if (cnt == n - 2) {
                    v.eb(x + 2);
                    v.eb(x - 1);
                    v.eb(x);
                    v.eb(x + 1);
                }
            }
        }
        outa(v, 2 * n - 1);
    }
    
}
