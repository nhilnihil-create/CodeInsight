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
    vector<bool> red(n, false);
    vector<int> num(n, 1);
    red[0] = true;
    rep(i, m) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        if(num[x] == 1) {
            if(red[x]) {
                red[x] = false;
                red[y] = true;
            }
        }
        else {
            if(red[x]) {
                red[y] = true;
            }
        }
        num[x]--;
        num[y]++;
    }
    int ans = 0;
    rep(i, n) {
        if(red[i]) ans++;
    }
    cout << ans << endl;
    return 0;
}
