#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main()
{
    int n, m;
    cin >> n >> m;
    
    const int nmmax = 50;
    char a[nmmax][nmmax], b[nmmax][nmmax];

    rep(y, n) {
        rep(x, n) {
            cin >> a[y][x];
        }
    }

    rep(y, m) {
        rep(x, m) {
            cin >> b[y][x];
        }
    }

    bool exist = false;

    rep(ly, n) {
        rep(lx, n) {
            if(ly + m - 1 >= n || lx + m - 1 >= n) continue;

            bool match = true;
            rep(y, m) {
                rep(x, m) {
                    if(a[ly + y][lx + x] != b[y][x]) match = false;
                }
            }
            if(match) exist = true;
        }
    }

    if(exist) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}
